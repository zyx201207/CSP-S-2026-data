#include<bits/stdc++.h>
#define int long long
#define fileIO(s) {freopen(s".in","r",stdin);freopen(s".out","w",stdout);}
using namespace std;
const int N=5e5+10;
int n,m,a[N],pre[N];
bool check(int target){
   for(int l=1;l+target-1<=n;l++){
//      cout<<"!!!l:"<<l<<"\n";
      int r=l+target-1;
//      cout<<"!!!r:"<<r<<"\n";
      int maxn=a[r];
      int need=maxn*target;
//      cout<<"!!!need:"<<need<<"\n";
      int nw=pre[r]-pre[l-1];
//      cout<<"!!!nw:"<<nw<<"\n";
      if(need-nw<=m){
         return 1;
      }
   }
   return 0;
}
signed main(){
   cin.tie(0)->sync_with_stdio(0);
   fileIO("crystal");
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++){
      pre[i]=pre[i-1]+a[i];
   }
   int l=1,r=n,ans=-1;
   while(l<=r){
      int mid=l+r>>1;
      if(check(mid)){
         ans=mid;
         l=mid+1;
      }
      else r=mid-1;
   }
   cout<<ans<<"\n";
}
/*
5 5
1 2 4 8 9
*/
