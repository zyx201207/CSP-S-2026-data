#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],f[500100],s[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int h=1;
	for(int i=1;i<=n;i++){
		while((s[i]-s[h]-(a[i]-a[h])*(h-1))>m)h++;
		f[i]=max(f[i-1],i-h+1);
	}
	cout<<f[n];
	return 0;
}
