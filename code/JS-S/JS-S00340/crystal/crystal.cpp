#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,ans=1;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		cnt=1;
		for(int j=i-1;j>=1;j--)
		{
			if(m>=(a[i]-a[j]))
			{
				m-=(a[i]-a[j]);
				cnt++;
			}	
		}
		if(cnt>ans) 
			ans=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
