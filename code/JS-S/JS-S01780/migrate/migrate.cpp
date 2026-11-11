#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,d,a[2000005],f[2000005],pre[2000005],nxt[2000005],g[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            nxt[i]=nxt[i-1];
            while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d) nxt[i]++;
            f[i]=g[i]=0;
           // cout<<nxt[i]<<" ";
        }
      //  cout<<"\n";
        pre[n+1]=n+1;
        for(int i=n;i>=1;i--){
            pre[i]=pre[i+1];
            while(pre[i]>1&&a[i]-a[pre[i]-1]<=d) pre[i]--;
         //   cout<<pre[i]<<" ";
        }
       // cout<<"\n";
       /* if(T==5){
            cout<<n<<" "<<d<<"\n";
            for(int i=1;i<=n;i++) cout<<a[i]<<" ";
            cout<<"\n";
        }*/
        ans=0;
        for(int i=1;i<=n;i++){
            if(nxt[i]==i) continue;
            f[nxt[i]]++;
            if(nxt[i]==nxt[i-1]) continue;
            f[nxt[i]]+=f[i];
        }
        for(int i=n;i>=1;i--){
            if(pre[i]==i) continue;
            g[pre[i]]++;
            if(pre[i]==pre[i+1]) continue;
            g[pre[i]]+=g[i];
        }
        for(int i=2;i<n-1;i++){
            //if(pre[i]!=pre[i+1]||nxt[i]!=nxt[i+1]) continue;
            if(nxt[i-1]==nxt[i]||pre[i+2]==pre[i]) continue;
           // cout<<i<<"\n";
            if(nxt[i]<=i+1) continue;
            if(pre[i+1]>=i) continue;
            ans+=(pre[i+2]-pre[i+1])*(nxt[i]-nxt[i-1]);
           // cout<<pre[i+2]-pre[i+1]<<" "<<nxt[i]-nxt[i-1]<<" ";
            //cout<<ans<<" ";
            if(pre[i]==pre[i+1]) ans+=f[pre[i]]*(nxt[i]-nxt[i-1]);
            if(nxt[i]==nxt[i+1]) ans+=g[nxt[i]]*(pre[i+2]-pre[i+1]);
            //cout<<ans<<" ";
            if(pre[i]==pre[i+1]&&nxt[i]==nxt[i+1]) ans+=f[pre[i]]*g[nxt[i]];
           // cout<<i<<" "<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 1
10 31746031746031745
-1000000000000000000 -777777777777777785 -555555555555555570 -333333333333333355
-111111111111111140 111111111111111075 333333333333333290 555555555555555505 777777777777777720 999999999999999935
*/
