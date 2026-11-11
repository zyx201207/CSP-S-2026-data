#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
long long a[N];
long long choose[N];
long long ans=0;
void dfs(int p,int m) {
	if(p==m+1) {
		long long in_ans=choose[1] & choose[2];
		for(int i=3;i<=m;i++) {
			in_ans=in_ans & choose[i];
		}
		ans=max(ans,in_ans);
		return ;
	}
	for(int i=p;i<=n-m;i++) {
		choose[p]=a[i];
		dfs(p+1,m);
	}
} 
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long mx=0;
	for(int i=1;i<=n;i++) {
		long long p;
		cin>>p;
		a[i]=p;
		mx=max(mx,p);
	}
	if(m==1) {
		cout<<mx;
		return 0;
	}
	dfs(1,m);
	cout<<ans;
}
