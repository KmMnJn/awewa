#include<iostream>
#include<time.h>
using namespace std;
int p[]={0,20,30,35,12,3};
int w[]={0,2,5,7,3,1};
int W=13;
int n = 5;
int maxprofit=0;
int pcount=0;
int ncount=0;
typedef struct node{
	int level;
	int profit;
	int weight;
	int bound;
}node;
class Queue{
	private:
		node* queue;
		int front,rear,capacity;
	public:
		Queue();
		bool empty();
		void push(node& item);
		node& pop();
};
Queue::Queue(){
	capacity=40000;
	queue=new node[capacity];
	front=rear=0;
}
bool Queue::empty(){
	return front==rear;
}
void Queue::push(node& item){
	queue[rear++]=item;
	int i=0,j=0;
	for(i=front;i<=rear-1;i++)
	{
		for(j=i+1;j<=rear;j++)
		{
			if(queue[j].bound > queue[i].bound)
			{
				node tmp;
				tmp=queue[j];
				queue[j]=queue[i];
				queue[i]=tmp;
			}
		}
	}
}
node& Queue::pop(){return queue[front++];}
void knapsack3();
float bound(node m);
int main(void){
	cout <<endl;
    cout << "0/1 knapsack problem - best-first-search"<<endl;
    cout << endl;
    for(int i = 1; i<n; i++){
        cout << "(" << p[i]  << ", " <<w[i] << "), ";
    }
    cout << "(" << p[n]  << ", " <<w[n] << ") " << endl;
    cout << "W = " << W << endl << endl;
    knapsack3();
    cout << "nodes visited : " << pcount + ncount << endl;
    cout << "max profit : " <<maxprofit << endl <<endl;
	return 0;
}
float bound(node m){
	int j,k; int totweight;
	int result;
	if(m.weight>=W)
		return 0;
	else{
		result=m.profit;
		j=m.level+1;
		totweight=m.weight;
		while((j<=n) && (totweight+w[j] <= W)){
			totweight=totweight+w[j];
			result=result+p[j];
			j++;
		}
		k=j;
		if(k<=n)
			result=result+(W-totweight)*(p[k]/w[k]);
		return result;
	}
}
void knapsack3(){
	Queue q;
	node u,v;
	v.level=0; v.profit=0; v.weight=0; v.bound=bound(v);
	pcount++;
	q.push(v);
	while(!q.empty()){
		v=q.pop();
		if(v.bound > maxprofit){
			u.level=v.level+1;
			u.profit=v.profit+p[u.level];
			u.weight=v.weight+w[u.level];
			if((u.weight<=W) && (u.profit>maxprofit))
				maxprofit=u.profit;
			u.bound=bound(u);
			if(u.bound > maxprofit)
			{
				q.push(u);
				pcount++;
			}
			else
				ncount++;
			u.weight=v.weight;
			u.profit=v.profit;
			u.bound=bound(u);
			if(u.bound > maxprofit)
			{
				q.push(u);
				pcount++;
			}
			else
				ncount++;
		}
	}
}