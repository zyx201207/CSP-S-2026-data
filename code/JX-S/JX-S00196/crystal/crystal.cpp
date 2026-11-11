#include<bits/stdc++.h>
using namespace std;
long long m,n;long long a[500005];long long b[500005];
int flag=0;int yu=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(i>=2&&a[i]!=a[i-1])flag=1;
    b[i]=a[i]-a[i-1];
}
if(flag==0){
cout<<n<<endl;
return 0;
}
else{
for(int i=2;i<=n;i++){
    if(b[i]!=b[i-1]){
            yu=1;
    }
}
if(yu==0){
  int i=1;
  while(m>0){
    m-=i*abs(b[2]);
    ++i;
  }
  if(m<0)i=i-1;
  cout<<i;
  return 0;
}
else{
sort(a+1,a+n+1);
int i=1;long long ans=0,cnt=1;
long long u=m;cnt=0;
for(int i=2;i<=n;i++){
        u=m;cnt=1;
    for(int j=i-1;j>=1;j--){
       u-=a[i]-a[j];
       cnt++;
       if(u<=0)break;
    }
    if(u<0)--cnt;
    for(int j=i+1;j<=n;j++){
        if(a[i]!=a[j])break;
        cnt++;
    }
    if(cnt>ans)ans=cnt;
}
 if(ans>n)cout<<n<<ans<<endl;
 else cout<<ans<<endl;return 0;
  }
  }return 0;
}
