#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,ans=1;
long long m,a[N],cst;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2,l=1;i<=n;++i)
	{
		cst+=(i-l)*(a[i]-a[i-1]);
		while(cst>m)
		{
			cst-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	cout.flush();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
