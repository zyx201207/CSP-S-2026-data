#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int b[N];
int c[N];
bool chk(int x){
    int res=0;
   for(int i=1;i<=n;i++){
    if(a[i]<=a[x]) res+=(a[x]-a[i]);
   }
   if(res<=m) return 1;
   return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int mx=-1;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,abs(a[i]));

   sort(a+1,a+n+1);
   if(n<=5000){
        int ans=0;
    for(int i=1;i<=n;i++){
            int res=0,cnt=0;
        for(int j=i;j>=1;j--){
           int x=a[i]-a[j];
      if(res+x<=m){
         res+=x;
         cnt++;
      }
        }
        ans=max(ans,cnt);
    }
     cout<<ans;
     return 0;
   }
   if(mx<=100){
        int ans=0;
        int cnt=1,tot=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]) cnt++;
     else c[a[i]]=cnt,b[++tot]=i;
        }
        for(int i=1;i<=tot;i++){
            int x1=a[b[i]];
            int res=0,cnt=0;
        for(int j=b[i];j>=1;j--){
           int x=x1-a[j];
      if(res+x<=m){
         res+=x;
         cnt++;
      }
        }
        ans=max(ans,cnt);
        }
   cout<<ans;
    return 0;
   }
   int l=1,r=n,ans=0;
   while(l<=r){
      int mid=(l+r)/2;
      if(chk(mid)){
        ans=mid;
        l=mid+1;
      }
      else{
        r=mid-1;
      }
   }
   printf("%lld",ans);
  return 0;
}
