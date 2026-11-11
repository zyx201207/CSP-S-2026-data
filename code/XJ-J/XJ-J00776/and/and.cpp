#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<int>());
	ans=a[0];
	for(int i=0;i<m;i++)
	{
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
}
