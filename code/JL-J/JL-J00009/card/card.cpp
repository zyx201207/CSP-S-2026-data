#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool upupup=true;
    int to[m+1],a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i])upupup=false;
        to[a[i]]=i+1;
    }
    if(upupup){
        for(int i=1;i<=m;i++){
            cout<<to[i]-1<<' ';
        }return 0;
    }
    int ans[m+1];
    memset(ans,0,sizeof ans);
    for(int st=1;st<=n;st++){
        int nowid=st;
        while(nowid<=n){
            ans[a[nowid]]++;
            nowid=to[a[nowid]];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
//Trick||Treat!
