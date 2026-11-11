#include<bits/stdc++.h>
#define int long long//long long
using namespace std;
const int N=5e5+5;
int a[N],pre[N];
bool cmp(int a,int b) {
	return a<b;
}
signed main() {
	//freopen
	freopen("crystal.in","r",stdin);
	freopen("crystsl.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);//≈≈–Ú
	for(int i=1; i<=n; i++)
		pre[i]=pre[i-1]+a[i];//«∞◊∫∫Õ
	int r=1,maxn=1;
	for(int i=1; i<=n; i++) { //À´÷∏’Î
		while(r<n&&a[r+1]*(r-i+2)-pre[r+1]+pre[i-1]<=m)
			r++;
		maxn=max(maxn,r-i+1);
	}
	cout<<maxn;
	return 0;
}

