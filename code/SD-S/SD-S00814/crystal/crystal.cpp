//I love Á÷Ó© forever
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long n,m;
long long nums[N],qian[N];
long long ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
		nums[i]+=(long long)1000000000002;
	}
	sort(nums+1,nums+n+1);
	for(int i=1;i<=n;i++)
	{
		qian[i]=qian[i-1]+nums[i];
	}
	long long l=n;
	for(int i=n;i>=1;i--)
	{
		while(l>=1&&(nums[i]*(i-l+1)*1ll)-(qian[i]-qian[l-1])<=m)
		{
		//	cout<<(nums[i]*(i-l+1)*1ll)-(qian[i]-qian[l-1])<<endl;
			l--;
		}
		if(l==0)
		{
			ans=max(ans,i-l);
			cout<<ans<<'\n';
			return 0;
		}
		ans=max(ans,i-l);
	//	cout<<i<<" "<<l<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
