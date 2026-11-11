#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
int a[2000005],b[2000005],flag[2000005];
void f(int l,int r){
if(b[r]==b[l]+1)flag[r]+=flag[l];
if(b[r]>b[l]+1)flag[r]=0;
flag[r]=min(b[r],b[l]+1);
while(a[r]-a[l]<=d&&r<=n){
      f(l,r);
      r++;
      }
if(l+2<=n)
f(l+1,l+2);

}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
        ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
            cin>>a[i];
flag[i]=1;
    }
   f(1,2);


    for(int i=1;i<=n;i++)
        if(flag[i]==2)ans++;
   cout<<ans<<endl;
    }
return 0;
}
