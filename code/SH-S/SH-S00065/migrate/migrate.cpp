#include <bits/stdc++.h>
using namespace std;
long long x[310],f[310];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n;
    long long d;
    cin>>c>>t;
    int ans;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;++i)cin>>x[i];
        for(int s=1;s<n;++s){
            memset(f,0,sizeof(f));
            f[s]=1;
            for(int j=s;j<n;++j){
                for(int k=j+1;k<=n&&x[k]-x[j]<=d;++k){
                    f[k]+=f[j];
                }
            }
            for(int i=s+1;i<=n;++i){
                if(f[i]==2)++ans;
            }
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}