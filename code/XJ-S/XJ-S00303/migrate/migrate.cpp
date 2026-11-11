#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,c,t;
long long d,x[N],f[N],st[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            cin>>n>>d;
            long long ans=0;
            for(int i=1;i<=n;i++) cin>>x[i];
            for(int u=1;u<=n;u++){
                long long sum=2e18,minn=0;
                f[u]=1,st[u-1]=st[u]=0;
                for(int v=u+1;v<=n;v++) f[v]=0;
                for(int v=u+1;v<=n;v++){
                    long long w=x[v]-x[v-1];
                    if(w>d) break;
                    if(sum+w<=d)
                        sum+=w;
                    else
                        minn++,sum=w;
                    st[v]=minn;
                    for(int k=v-1;x[v]-x[k]<=d&&k>=u;k--)
                        if(st[k]+1==minn) f[v]+=f[k];
                    ans+=(f[v]==2);
                }
            }
            cout<<ans<<"\n";
        }
    }else if(c<12){
        while(t--){
            cin>>n>>d; 
            for(int i=1;i<=n;i++) cin>>x[i];
            long long xx=x[2]-x[1];
            long long k=d/xx;
            long long x=2*k-1;
            // cout<<d<<" "<<xx<<" "<<k<<" "<<x<<" ";
            if(k<=1||x>n){
                cout<<"0\n";
                continue;
            }
            cout<<n-x<<"\n";
        }
    }
    return 0;
}
