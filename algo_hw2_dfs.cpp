#include <iostream>
using namespace std;
int p[]={0,20,30,35,12,3}; //profit
int w[]={0,2,5,7,3,1}; // weight
int W = 13;
int n = 5;
int maxprofit = 0;
int maxweight;
int visit_count = 0;
void knapsack(int k,int profit,int weight);
float bound(int profit,int weight,int i);
int main(void){
    cout <<endl;
    cout << "0/1 knapsack problem - depth-first-search"<<endl;
    cout << endl;
    for(int i = 1; i<n; i++){
        cout << "(" << p[i]  << ", " <<w[i] << "), ";
    }
    cout << "(" << p[n]  << ", " <<w[n] << ") " << endl;
    cout << "W = " << W << endl << endl;
    knapsack(0, p[0], w[0]);
    cout << "nodes visited : " << visit_count << endl;
    cout << "max profit : " <<maxprofit << endl <<endl;
    return 0;
}
void knapsack(int k,int profit,int weight){
    if (weight <= W && profit > maxprofit){
        maxprofit = profit;
    }
    if (bound(profit, weight, k) > maxprofit)
    {
        knapsack(k+1, profit+p[k+1], weight+w[k+1]);
        knapsack(k+1, profit, weight);
    }
}
float bound(int profit,int weight,int i){
    visit_count++;
    int j, k;
    int result, totweight;
    if (weight >= W)
        return 0;
    else{
        result = profit;
        j = i + 1;
        totweight = weight;
    }
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