#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
int m;
int cnt;

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=0;i<n-1;i++)
		{
			//Äú
			//!³­!!!!!!!!!!!!!!!!!!!aaaaa!!!!!!!!!!!!!!?????????????????????????????????????????
			//ºÃ 
			cnt+=(a[i]&a[i+1]);
			 
		}
		cout<<cnt<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cnt=max(cnt,a[i]&a[j]);
		}
		
	}
	cout<<cnt;
	return 0;
}
