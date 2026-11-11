#include <bits/stdc++.h>
using namespace std;
int a[305],n,d,ans;
int c,T;
int mmmmm(int u,int v)
{
	int o = d;int q[305];string s1,s2;
	for(int i = 0;i < 305;i++)q[i]=0;
	for(int i = u;i < v;i++)
	{
		if(d<a[i+1]-a[i])return 0;
		if(o<a[i+1]-a[i])
		{
			o=d;
			char ss=i+'0';
			s1+=ss;
		}
		else o-=a[i+1]-a[i];
	}
	o = d;
	for(int i = v;i > u;i--)
	{
		if(o<a[i]-a[i-1])
		{
			o=d;q[i-1]++;
			char ss=i+'0';
			s2=ss+s2;
		}
		else o-=a[i]-a[i-1];
	}
	o = d;
	if(s1[0]-'0'+s2[0]-'0'==n+1)return 0;
	//cout << s1 << " " << s2 << endl;
	if(s2!=s1)return 1;
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		ans=0;
		cin >> n >> d;
		for(int i=1;i <= n;i++)cin>>a[i];
		for(int i = 1;i < n;i++)
		{
			for(int j = i+1;j <= n;j++)
			if(mmmmm(i,j))
			{
				ans++;
				
				
				//cout << i << " "<< j << endl;
			}
		}
		cout << ans << endl;
	}
	
}
