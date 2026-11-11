#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long pla[2000010];
long long n,d;
long long ans[100010];
void cl()
{
	for(int i=0;i<=2000000;i++)pla[i]=0;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	for(int tu=1;tu<=t;tu++)
	{
		cin>>n>>d;
		cl();
		for(int i=1;i<=n;i++)
		{
			cin>>pla[i];
		}
		for(int i=2;i<=n;i++)
		{
			if(pla[i]-pla[i-1]>d)ans[tu]=0;
		}
		if(c==11 || c==12)
		{
			if(pla[2]-pla[1]==d)
			{
				ans[tu]=0;
			}
			else
			{
				ans[tu]=(pla[2]-pla[1]+d-1)/d;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
}
