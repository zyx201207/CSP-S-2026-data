#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
int a[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+1+n);
int sum=a[n];
for(int i=n;i>=n-m+1;i--){
	sum&=a[i];
}
cout<<sum;
return 0;
}

