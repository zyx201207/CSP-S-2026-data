#include<bits/stdc++.h>
using namespace std;
int n,a[10000000];
int cpp(int x,int y){
return x<y;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){cin>>a[i];}
sort(a,a+n+1,cpp);
if(n%2==1)cout<<a[n/2+1];
if(n%2==0)cout<<a[n/2];
return 0;
}
