#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int maxn=5e5+1;
long long a[maxn],num,sum;
priority_queue<int,vector<int>,greater<int>>pq;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pq.push(a[i]);
    }
    stable_sort(a+1,a+1+n);
    num=1;
    while(!pq.empty() and pq.size()!=1){
        int t1=pq.top();
        pq.pop();
        int t2=pq.top();
        pq.pop();
        m-=(t2-t1);
        if(m<0){
            break;
        }else{
            num++;
            pq.push(t2*2);
        }
    }
    cout<<num;
    return 0;
}
