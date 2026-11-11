#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[200002],sum;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
sum=a[n];
for(int i=n-1;i>n-m;i--){
    sum=sum&a[i];
}
cout<<sum;

return 0;
}
