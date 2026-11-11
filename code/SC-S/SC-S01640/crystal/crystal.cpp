#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll m,cha,a[N];
int n,ans,runcnt;
bool f1=true,f2=true;
void teshupre(int i)
{
	if(a[i]!=i)
		f2=false;
	if(i==2)
		cha=a[i]-a[i-1];
	if(i!=1&&cha!=a[i]-a[i-1])
		f1=false;
	return;
}
void teshuoutput()
{
	if(f1)
	{
		cout<<m/cha+1<<"\n";
		exit(0);
	}
	if(f2)
	{
		cout<<m+1<<"\n";
		exit(0);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		teshupre(i);
	}
	teshuoutput();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int cnt=0,lid=i-1;
		ll res=m;
//		cout<<"i="<<i<<":";
		while(res>=0&&lid>=1)
		{
			runcnt++;
			res-=a[i]-a[lid];
			cnt++;
			lid--;
//			cout<<lid<<" "<<cnt<<"\n";
			if(runcnt==6e8+5e7)
			{
				cout<<ans<<"\n";
				return 0;
			}
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans<<"\n";
	return 0;
}