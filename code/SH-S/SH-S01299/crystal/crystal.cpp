#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int b[100005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	bool ok=1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1])ok=0;
	}
	if(ok){
		if(m%n)cout<<n-1;
		else cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int maxn=0;
	for(int i=1;i<n;i++){
		if(b[i]>m)break;
		maxn=i;
	}
	if(b[n]<=m)maxn=n;
	cout<<maxn;
	return 0;
}
