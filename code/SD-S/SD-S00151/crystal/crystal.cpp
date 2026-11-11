#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e5;
const int M=1e3+1e2;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	int maxn=-1e18;
	for(int x=1,y=1;y<=n;y++){
		sum+=(a[y]-a[x-1])*(y-x)*1ll;
		for(;sum>m;x++){
			sum-=a[y]-a[x];
			maxn=max(maxn,y-x+1);
		}
	}
	cout<<maxn;
	return 0;
}
