#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int lef[N],rig[N],x[N],pre[N],suf[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%lld%lld",&c,&T);
    while(T--){
        int n,d;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        int res=1;
        for(int i=1;i<=n;i++){
            while(x[i]-x[res]>d)res++;
            lef[i]=res;
        }
        lef[n+1]=n+1;
        res=n;
        for(int i=n;i>=1;i--){
            while(x[res]-x[i]>d)res--;
            rig[i]=res;
        }
        rig[0]=0;
        for(int i=1;i<=n;i++){
            if(lef[i]==lef[i+1])pre[i]=0;
            else pre[i]=pre[lef[i]]+lef[i+1]-lef[i];
        }
        for(int i=n;i>=1;i--){
            if(rig[i]==rig[i-1])suf[i]=0;
            else suf[i]=suf[rig[i]]+rig[i]-rig[i-1];
        }
        int ans=0;
        for(int i=1;i<=n-3;i++){
            if(rig[i]<=i+1)continue;
            if(rig[rig[i]-1]!=rig[rig[i]])continue;
            if(lef[rig[i]-1]!=i)continue;
            if(rig[rig[i]-2]==rig[rig[i]])continue;
            ans+=pre[i]*suf[rig[rig[i]]];
        }
        for(int i=1;i<=n-3;i++){
            if(rig[i]<=i+1)continue;
            if(lef[rig[i]-1]!=i)continue;
            if(max(rig[rig[i]-2],rig[i])>=rig[rig[i]-1])continue;
            ans+=pre[i]*(rig[rig[i]-1]-max(rig[rig[i]-2],rig[i]));
        }
        for(int i=n;i>=4;i--){
            if(lef[i]>=i-1)continue;
            if(rig[lef[i]+1]!=i)continue;
            if(min(lef[lef[i]+2],lef[i])<=lef[lef[i]+1])continue;
            ans+=suf[i]*(min(lef[lef[i]+2],lef[i])-lef[lef[i]+1]);
        }
        for(int i=3;i<n;i++)if(lef[i]<i-1&&rig[i-1]>i){
            ans+=(min(i-1,lef[i+1])-lef[i])*(rig[i-1]-max(i,rig[i-2]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//Igunareo ver.

//Good night.
//That's the end.