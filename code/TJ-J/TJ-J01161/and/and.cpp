#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const long long M=2e30-1;
int n,m;
long long a[N],ans=M;
int cmp(int x,int y) { return x>y; }
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}
