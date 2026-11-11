//zai daima zhong xiugai [c] shuzu wei [a] shi,zhi gai le [check] de diyige,qie zai [sum] houxu jisuan zhong shiyong le [sum-=],
//jieguo guole 3 ge yangli
//One BUG is BUG,many BUGs can work
//wo yi yansu renke yangli
//wang zhou zhi
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500025],c[500025],b[500025];
bool check(int z)
{
	int sum=0;
	for(int i=2;i<=z;i++)
	{
		sum+=(i-1)*c[i];
//		if(sum>1e18) 
//		{
//			cout<<"NO"<<'\n';
//			return false;
//		}
	}
//	cout<<sum<<" ";
	if(sum<=m) return true;
	
	for(int i=z+1;i<=n;i++)
	{
		sum+=(z-1)*c[i];
		sum=sum-b[i-1]+b[i-z];
		if(sum<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
		b[i]=b[i-1]+c[i];
//		cout<<c[i]<<" "<<b[i]<<'\n';
	}
	
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)==true)
		{
			ans=max(mid,ans);
			l=mid+1;
		}
		else r=mid;
	}
//	check(3);
	
	cout<<ans<<'\n';
	
	return 0;
}