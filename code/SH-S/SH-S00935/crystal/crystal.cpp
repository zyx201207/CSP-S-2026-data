#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long st=1,sum=0;
	for(int i=2;i<=n;i++)//至a[i]的最大水晶数
	{
		//加入a[i]
		sum+=(i-st)*(a[i]-a[i-1]);
		//删除多余的a[st]
		while(sum>m)sum-=a[i]-a[st++];
		ans=max(ans,i-st+1);
//		cout<<i<<" "<<st<<" "<<ans<<" "<<sum<<"\n";
	}
	cout<<ans<<endl;
	return 0;
}
