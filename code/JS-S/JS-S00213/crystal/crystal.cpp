#include<bits/stdc++.h>
using namespace std;
long long a[500001],pre[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	int ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[j]*(j-i+1)-(pre[j]-pre[i])-a[1]<=m)ans=max(ans,(j-i+1));
	cout<<ans;
}
