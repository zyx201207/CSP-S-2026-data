#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,p=0,p2,sum=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	p=p+a[i];
}
p2=p/n;
for(int i=1;i<=n;i++){
	if(p2>a[i]) b[i]=p2-a[i];
	else b[i]=a[i]-p2;
}
for(int i=1;i<=n;i++){
	if(b[i]<=m){
		m=m-b[i];
		sum=sum+1;
	}
}
cout<<sum;
return 0;
}
