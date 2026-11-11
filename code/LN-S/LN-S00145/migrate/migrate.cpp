#include<bits/stdc++.h>
using namespace std;
int c,t;//apt
int dist[2000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d,ans=0,fp=-1;
        cin>>n>>d;
        int x[n+1];
        for(int i=1;i<=n;i++){
            cin>>x[i];
            dist[i]=abs(x[i]-x[i-1]);
            if(dist[i]>d) dist[i]=-1;
        }
        for(int i=1;i<=n-3;i++){
            int j=i+3;
            if(dist[i+1]!=-1&&(dist[i+2]+dist[i+1])!=-1){
                if(dist[i+3]!=-1&&(dist[i+2]+dist[i+3])!=-1){
                    fp++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            dist[i]=-1;
        }
        if(fp==-1){
            cout<<0<<'\n';
            continue;
        }
        ans=1<<fp;
        cout<<ans<<'\n';
    }
    return 0;
}
