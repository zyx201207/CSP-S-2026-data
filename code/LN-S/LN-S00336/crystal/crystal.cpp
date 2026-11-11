#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> aa;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.in","w",stdout);
scanf("%lld%lld",&n,&m);
for(int i=1;i<=n;i++){
scanf("%lld",&aa[i]);
}
sort(aa+1,aa+1+n);
long long a=0,b=0;
if(aa[1]<=aa[n]){
for(int i=2;i<=n;i++){
b+=(aa[i]-aa[i-1])*(i-1);
if(b>m){
a=i-1;
break;
}
}
}else{
for(int i=n-1;i>=1;i++){
b+=(aa[i]-aa[i+1])*(n-i);
if(b>m){
a=n-i;
break;
}
}
}
printf("%lld",a);
return 0;
}
