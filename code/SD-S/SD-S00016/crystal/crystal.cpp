#include<bits/stdc++.h>
using namespace std;
int n,j,mx;
long long m,a[500005],f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[i]*(i-j)-f[i]+f[j]>m)	j++;
		mx=max(mx,i-j);
	}
	cout<<mx;
	return 0;
}
