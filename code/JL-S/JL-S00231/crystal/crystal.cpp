#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000001];
int main(){
  freopen("crystal.in","r",stdin);
   freopen("crystalt.out","w",stdout);
int cnt=m,ans=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
for(int i=1;i<n;i++){
    if(a[n]-a[1]>m){
    a[n-1];
}
else{
a[i]+=a[n];
cnt-=n;
ans++;
}
break;
}

cout<<ans;
return 0;
}

