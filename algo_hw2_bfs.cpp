#include <iostream>
#include <queue>
using namespace std;
int p[] = {20,30,35,12,3};
int w[] = {2, 5, 7, 3, 1};
int W = 13;
int n = 4;
int maxprofit = 0;
int pcount;
int ncount;
struct node{
    int level;
    int profit;
    int weight;
};
void knapsack();
float bound(node u);
int main(){
    cout <<endl;
    cout << "0/1 knapsack problem - breath-first-search"<<endl;;
    cout << endl;
    for(int i = 0; i<n; i++){
        cout << "(" << p[i]  << ", " <<w[i] << "), ";
    }
    cout << "(" << p[n]  << ", " <<w[n] << ") " << endl;
    cout << "W = " << W << endl << endl;
    knapsack();
    cout << "nodes visited : " << pcount + ncount << endl;
    cout << "max profit : " <<maxprofit << endl <<endl;
}
void  knapsack(){
    queue <node> q;
    node u, v;
    v.level = -1; v.profit = 0; v.weight = 0;
    pcount++;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        u.level = v.level + 1;
        u.profit = v.profit + p[u.level];
        u.weight = v.weight + w[u.level];

        if (u.weight <= W && u.profit > maxprofit)
            maxprofit = u.profit;
        if (bound(u) > maxprofit){
            q.push(u);
            pcount++;
        }else
            ncount++;
        u.weight=v.weight;
        u.profit=v.profit;
        if(bound(u) > maxprofit){
            q.push(u);
            pcount++; // 유망한 노드
        }
        else
            ncount++; // 유망하지 않은 노드
    }
}
float bound(node u){
    int j, k, totweight;
    int result;
    if (u.weight >= W)
        return 0;
    else{
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;
        while ((j <= n) && (totweight + w[j] <= W)){
            totweight = totweight + w[j];
            result = result + p[j];
            j++;
        }
        k = j;
        if (k <= n)
            result = result + (W - totweight) * p[k]/w[k];
        return result;
    }
}