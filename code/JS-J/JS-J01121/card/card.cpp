#include<bits/stdc++.h>
using namespace std;
const int N=500007,M=300007;
int n,m;
int ans[M],vis[M],a[N],p[M];
stack<int> s;
main(){
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    /*
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(s.top()!=a[j]){
                    vis[s.top()]=0;
                    s.pop();
                }
            }
            else s.push(a[j]);
            vis[a[j]]=1;
        }
        while(!s.empty()){
            ans[s.top()]++;
            vis[s.top()]=0;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){cout<<ans[i]<<' ';}
        */
    cin>>n>>m;
    //cout<<n<<m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<a[i];
    }
    for(int i=n;i>0;i--){
        if(!vis[a[i]]){
            p[a[i]]=i;
            vis[a[i]]=1;
        }
    }
    //for(int i=1;i<=n;i++){cout<<p[a[i]]<<' ';}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            ans[a[j]]++;
            j=p[a[j]]+1;
        }
        //return 0;
    }
    for(int i=1;i<=m;i++){cout<<ans[i]<<' ';}
    return 0;
}
