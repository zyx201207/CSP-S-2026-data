#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],sum=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
cin>>a[i];
}
for(int i=0;i<(n*(n-1))/2;i++){
b[i]=a[i]&a[i-1];
sum=b[i];
b[i]=0;
}
cout<<max(sum);
}
