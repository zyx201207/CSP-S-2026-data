#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=1,ans=0,sum=0;
	while(l<=n&&r<=n&&l<=r)
	{
		long long tmp=a[r]*(r-l+1)-s[r]+s[l-1];
		if(tmp<=m)r++,ans=max(ans,r-l);
		else l++; 
	//	cout<<l<<" "<<r<<" "<<tmp<<" "<<ans<<endl;
	}
	cout<<ans;
} 
//一开始想的是差分，但是一直算一直算就是要n^2，结果一小时后才发现可以是双指针:(
//15:59写完的，哭哭慢死了 
