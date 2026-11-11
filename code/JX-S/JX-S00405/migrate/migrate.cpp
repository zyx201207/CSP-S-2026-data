/*
uid=305928 last fight

azayagana risouhatasutsurukiyo
konoyonoyume subetenosete
ima ima saa kirisaite
tashikana kotowariminna urayamu
mitasarenu sekainoitadakide!

For lovely Tenshi Hinanawi
 */


/*
NO one can stop her from steping forward.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],b[1000005];
int f[1000005],g[1000005],h[1000005],x[1000005];
void solve(){
  cin>>n>>m;
  for (int i=1;i<=n;i++)cin>>a[i];
  int j=1;
  for (int i=1;i<=n;i++){
    while (j<n&&a[j+1]-a[i]<=m)++j;
    b[i]=j;
  }
  for (int i=1;i<=n;i++){
    f[i]=g[i]=0;
  }
  h[n+1]=0,x[n+1]=0;
  for (int i=n;i>=1;i--){
    if (b[i]==i){
      f[i]=1,g[i]=0;
      continue;
    }
    else{
      int j=b[i];
      if (b[j]==j){
	f[i]=j-i+1,g[i]=0;
	continue;
      }
      int k=b[j];
      if (b[j-1]>=k){
	f[i]=j-i+1;
      }
      else{
	f[i]=(j-i+1)+(k-b[j-1]-1)+f[k];
      }
      if (j==i+1){
	g[i]=g[j];continue;
      }
      if (b[j-2]>=k){
	g[i]=0;continue;
      }
      g[i]=b[j-1]-b[j-2];
      if (b[j-1]==k){
        g[i]+=f[k]-1;
      }
      else{
	g[i]+=g[j];
      }
      
    }
    h[i]=h[i+1]+f[i];
  }
  int ans=0;
  for (int i=1;i<=n;i++){
    //cout<<b[i]<<" "<<f[i]<<" "<<g[i]<<"\n";
    ans+=g[i];
  }
  cout<<ans<<"\n";
}
signed main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c,t;cin>>c>>t;
  while (t--)solve();
  return 0;
}
