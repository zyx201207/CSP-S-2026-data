#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000100];
long long b[1000100];
bool f(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int j=i+x-1;
		long long cnt=(x*a[j]-(b[j]-b[i-1]));
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n;
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(f(mid)) l=mid;
		else r=mid-1;
	}
	cout << r;
	return 0;
}

