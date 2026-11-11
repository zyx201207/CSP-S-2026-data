#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN=2e5+7;
int n,m;
ll ani[MAXN];
bool cmp(long long &x,long long &y) {
	return x>y;
}
ll ans=0LL;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>ani[i];
	}
	sort(ani+1,ani+n+1,cmp);
	ans=ani[1];
	for(int i=1; i<=m; i++) {
		ans&=ani[i];
	}
	cout<<ans<<'\n';
	return 0;
}
