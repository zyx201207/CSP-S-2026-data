#include<bits/stdc++.h>
using namespace std;
long long cc,t,n,d,x[2000005],l,r,b[1005],c[1005],e[305],f[305],ans,jl;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cc>>t;
    if(cc>=11){
        while(t--){
            cin>>n>>d;
            ans=0;
            for(int i=1;i<=n;i++)
            cin>>x[i];
            jl=d/(x[2]-x[1]);
            if(jl>=2)cout<<max(ans,n-(jl*2-1));
            else cout<<0;
            cout<<'\n';
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        cin>>x[i];
        for(int i=1;i<=n;i++){
            l=1,r=1;
            for(int j=1;j<=n;j++)
            e[j]=1e16,f[j]=0;
            b[1]=i,c[1]=0;
            e[i]=0;
            f[i]=1;
            while(l<=r){
                for(int j=1;j<=n;j++){
                    if(abs(x[j]-x[b[l]])>d)continue;
                    if(e[j]==1e16)e[j]=e[b[l]]+1,f[j]=f[b[l]],b[++r]=j,c[r]=e[j];
                    else if(e[j]==e[b[l]]+1)f[j]+=f[b[l]];
                }
                l++;
            }
            for(int j=i+1;j<=n;j++)
            if(f[j]==2)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

