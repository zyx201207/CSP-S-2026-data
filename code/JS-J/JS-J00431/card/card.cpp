#include<bits/stdc++.h>
using namespace std;
long long n,m,a[4000000],ans[10101011];
long long cnt[1000000];//cnt[];
int main(){
freopen("card.in","r",stdin);
freopen("card.in","r",stdin);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
    queue<long long,int>q;
    for(int j=i;j<=n;j++){
        q.push(a[j]);
        cnt[a[j]]++;
    }
    while(1){
            bool dfg=1;
        for(long long i=0;i<q.size();i++){
            if(cnt[q[i]]>=1ll+1)dfg=0;
        }
    if(dfg)for(int i=0;i<q.size();i++){
            ans[q[i]]++;

        }
    }
    if(dfg)break;
    int y=q.front();
    if(cnt[q]==1){
        q.pop();
        q.push(y);
    }
    else{
            q.pop();
        while(1){
            if(q.front()==y){
                q.pop();
                q.push(y);
                break;
            }
            q.pop();
        }
    }
}
for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
return 0;
}
