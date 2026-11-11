#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,maxn=1,ans=1;
long long m,a[N],b[N],cost=0,st,ed;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i) {
		b[i]=a[i]-a[i-1];
		cost+=b[i]*ans;
		while(cost>m) {
			cost-=a[i]-a[st++];
			ans--;
		}
		ans++;
		maxn=max(maxn,ans);
	}
	cout<<maxn<<endl;
	return 0;
}
