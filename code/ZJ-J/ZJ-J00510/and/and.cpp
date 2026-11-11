#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],f[200009],ma2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;--i){
		if(a[i]==a[i-1]){
			ma2=a[i];
			break;
		}
	}
	if(n==2&&ma2!=0){
		cout<<ma2;
		return 0;
	}
	f[1]=a[n];
	for(int i=n-1;i>=1;--i){
		for(int j=m;j>1;--j){
			f[j]=max(f[j],(f[j-1]&a[i]));
		}
	}
	cout<<f[m];
}
