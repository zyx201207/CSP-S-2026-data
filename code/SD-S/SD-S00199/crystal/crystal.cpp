#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
int a[N];
int n,m;

bool cmp(int xx,int yy)
{
	return xx < yy;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	
	int ans = 0,j = n;
	int c = 0;
	for (int i = n;i >= 1;i--)
	{
		int cnt = m;
		if(i != n) c = c-(a[i+1]-a[i])*(i+1-j);
		cnt-=c;
//		cout<<"@"<<j<<' '<<c<<"\n";
		while (1)
		{
			if(j == 1 || abs(a[i]-a[j-1]) > cnt) break;
			j--;
			cnt = cnt-abs(a[i]-a[j]);
			c += abs(a[i]-a[j]);
		}
		ans = max(ans,i-j+1);
	}
		
	cout<<ans<<'\n';
	return 0;
}
