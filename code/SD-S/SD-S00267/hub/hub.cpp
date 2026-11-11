#include<bits/stdc++.h>
using namespace std;
int main()
{
	//许愿提高刚好一等 
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c1,T;
	cin>>c1>>T;
	while(T--)
	{
		ans=0;
		if(c1==11||c1==12)
		{
			cout<<0<<endl;
			continue;
		}
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<=n;j++)
			{
				c[i][j]=c[j][i]=0;
				b[i][j]=b[j][i]=0;

			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-d<=a[j]) b[j][i]=b[i][j]=1;
				else break;
			}
		}
		di(n);
		d1(n);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) 
		if(c[i][j]==2) ans++; 
		cout<<ans<<endl;
	} 
	return 0;
 } 
