#include<bits/stdc++.h>
using namespace std;
int a[300010],s[300010],s1[300010];
int am;
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	s[1]=a[1];
	s1[2]=a[2];
	for(int i=3;i<=n;i++)s1[i]=s1[i-1]&a[i];
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]&a[i];
		am=max(am,a[i]);
	}
	if(m==1)cout<<am;
	else if(m==n)cout<<s[n];
	else if(m==n-1)cout<<max(s[n-1],s1[n]);
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,s[i]);
		cout<<ans;
	}
	return 0;
}
