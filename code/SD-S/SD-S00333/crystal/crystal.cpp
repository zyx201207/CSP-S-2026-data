#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
long long pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int z=0;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		while((i-z)*a[i]-(pre[i]-pre[z])>m)z++;
		maxn=max(maxn,i-z);
		//cout<<z<<'\n';
	}
	cout<<maxn<<'\n';
	return 0;
}

