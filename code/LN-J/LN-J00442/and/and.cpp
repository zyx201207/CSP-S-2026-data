#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300005];
bool cmp(int a,int b){
return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1,cmp);
for(int i=2;i<=m;i++){
    a[i]&=a[i-1];
}
cout<<a[m];
return 0;
}
