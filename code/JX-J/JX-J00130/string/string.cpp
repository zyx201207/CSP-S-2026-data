#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,a[200005],ans;
char c[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++){
       cin>>a[i]>>c[i];
   }
   LL l=1,r=n,i=0,j=0,cnt=0;
   while(l<r){
       //cout<<l<<' '<<r<<'\n';
       if(a[l]-i<=a[r]-j){
           if(c[l]!=c[r]){
               cnt+=a[l]-i;
           }
            j+=a[l]-i;
            i=0;
            l++;
            if(j==a[r]){
                r--;
                j=0;
            }
       }else{
           if(c[l]!=c[r]){
                cnt+=a[r]-j;
           }
            i+=a[r]-j;
            j=0;
            r--;
       }
   }
    cout<<cnt;
    return 0;
}