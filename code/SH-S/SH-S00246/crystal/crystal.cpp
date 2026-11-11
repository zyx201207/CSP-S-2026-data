#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
long long n,m,a[1000005],pre[1000005];
int tot=0,len=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int fans=0;
	for(int i=1;i<=n;i++)
	{
		int L=0,R=i,res=-1;
		while(L<=R)
		{
			int mid=(L+R)/2;
			if(1ll*(i-mid)*a[i]-pre[i]+pre[mid]<=m) res=mid,R=mid-1;
			else L=mid+1;
		}
		if(res!=-1) fans=max(fans,i-res);
	}
	cout<<fans<<"\n";
	return 0;
}
