#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cone(int a){
    int sum=0;
    while(a){
        if(a&1)sum++;
        a>>=1;
    }
    return sum;
}
priority_queue<pair<int,int> >pq;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=-1,ansn=(1<<30)-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(m==1)maxn=max(maxn,x);
        else if(m==n)ansn&=x;

        pq.push({cone(x),x});
    }
    if(m==1){cout<<maxn;return 0;}
    else if(m==n)cout<<ansn;
    else if(m==n-1)cout<<0;
    int ans=pq.top().second;
    pq.pop();
    m--;
    while(m--){
        ans&=pq.top().second;
        pq.pop();
    }
    cout<<ans;
    return 0;
}
