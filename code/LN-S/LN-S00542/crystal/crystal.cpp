#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
int n,m,num=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
sort(a,a+n+1);
for(int i=1;i<=n;i++){
 if(a[i]<=a[(n+1)/2]){
    num++;
 }
}
cout<<num;

return 0;
}
