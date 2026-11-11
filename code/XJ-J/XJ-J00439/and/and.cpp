#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+6;
long long n,a[N],maxn,m,maxnn;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxnn=max(a[i],maxnn);
	if(m==1)
	{
		cout<<maxnn;
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) maxn=max(maxn,a[i]&a[j]);
	cout<<maxn;
	return 0;
}