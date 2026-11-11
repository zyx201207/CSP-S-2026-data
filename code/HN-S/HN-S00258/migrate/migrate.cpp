#include<bits/stdc++.h>
using namespace std;
int n[100005],d[100005],x[2000005][10],s=0,ans=0,sum=0;
int f(int b,int g,int u)
{
	if(b>=g)
	{
		if(ans>s)
		{
			ans=1;
			s=0;
		}
		ans++;
	 } 
	for(int i=1;i<=u;i++)
	{
		s++;
		f(b+u,g,u);
	}
	return ans;
}
int main()
{
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[j][i];
			for(int h=j+1;h<=n[i];h++)
			{
				if(2==f(x[j][i],x[h][i],d[i])) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
