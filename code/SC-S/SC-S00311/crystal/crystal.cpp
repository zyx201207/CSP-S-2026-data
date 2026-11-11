#include<bits/stdc++.h>
using namespace std;
int a;long long b,h[200010],k[10010],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>h[i];
	}sort(h+1,h+a+1);
	if(a<=5000&&b<=1000000000){
		for(int i=a;i>=1;i--)
		{
			int u=b;
			for(int j=i-1;j>=1;j--)
			{
				if(h[i]-h[j]<=u)
				{
					k[i]++;
					u-=(h[i]-h[j]);
				}else break;
			}
		}for(int i=1;i<=a;i++)ans=max(ans,k[i]);
		cout<<ans+1;
	}else{
		long long u=h[2]-h[1],i=1;
		while(i*u<=b){
			ans++;
			i=i+ans+1;
		}
		cout<<ans+1;
	}
	return 0;
}