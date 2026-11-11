#include <bits/stdc++.h>
using namespace std;
long long a[500001],m,n;
long long pre[500001];//Chinesecanfly
int fth(int b){
    int l=1,r=b;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if((b-mid)*a[b]-pre[b-1]+pre[mid-1]<=m){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if(ans==-1)return b;
    return ans;
}
int main(){

   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n;
   cin>>m;
   for(int i=1;i<=n;i++){
       cin>>a[i];

   }
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++){
       pre[i]=pre[i-1]+a[i];
   }
   int ans=1;
   for(int i=n;i>=1;i--){
       ans=max(ans,i-fth(i)+1);

   }
   cout<<ans<<endl;
}
