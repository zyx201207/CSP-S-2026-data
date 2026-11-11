#include<bits/stdc++.h>
using namespace std;
main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+2],mark[m+2],cnt[m+2];
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int s=1;s<=n;s++){
        memset(mark,0,sizeof mark);
        stack<int>x;
        for(int i=s;i<=n;i++){
            if(mark[a[i]]){
                while(x.size()&&x.top()!=mark[a[i]])mark[a[x.top()]]=0,x.pop();
                x.pop();
            }
            mark[a[i]]=i,x.push(i);
        }
        while(x.size())cnt[a[x.top()]]++,x.pop();
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
}
