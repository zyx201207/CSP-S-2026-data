#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long a[5000005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
if(n!=m) sort(a,a+n);
cnt=a[n-1];
for(int i=n-1;i>n-1-m;i--){
    cnt&=a[i];
}
cout<<cnt;
fclose(stdin);
fclose(stdout);
return 0;
}
