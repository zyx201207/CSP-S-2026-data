#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2048575],l[2048575],r[2048575],p,ps[2048575],fl,ans,w;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d,p=1,ans=0;
        for(int i=1;i<=n;i++)cin>>x[i],l[i]=n+1;
        for(int i=1;i<=n;i++){
            p=max(p,i*1ll);
            while(p<n&&x[p+1]-x[i]<=d)p++;
            r[i]=p,l[p]=min(l[p],i*1ll);
            if(x[i]-x[1]<=d)l[i]=1;
        }for(int i=1;i<n-2;i++)for(int j=i+3;j<=n;j++){
            p=i,w=fl=0;
            while(p<j)p=min(j*1ll,r[p]),ps[++w]=p;
            for(int i=w;i>1;i--)if(ps[i-1]>l[ps[i]]){
                if(ps[i-1]==l[ps[i]]+1)fl++;
                else break;
            }ans+=(fl==1);
        }cout<<ans<<"\n";
    }return 0;
}//LuoGu 534898
//hai he wo thx
//wssb
