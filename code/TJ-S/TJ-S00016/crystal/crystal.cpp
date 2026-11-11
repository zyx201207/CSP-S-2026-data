#include<bits/stdc++.h>

using namespace std;
int n,m,a[500005],cnt;
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
		for(int j=1;j<i;j++)
		{
			cnt+=a[i]-a[j];
		}
		if(cnt==m){
		
			cout<<i;
			return 0;
		}
		else if(cnt>m){
			cout<<i-1;
			return 0;
		} 
		else
			cnt=0;
	}
	return 0;	
} 
