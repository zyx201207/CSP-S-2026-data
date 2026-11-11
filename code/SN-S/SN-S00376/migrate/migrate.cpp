//张海辰 西安铁一中滨河学校高级中学 SN-S00376
#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long b[10000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int cnt=0;
	for(int i=1;i<=t;i++)
	{
		int n;
		long long d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			int k=1;
			if((a[j]-a[k])%d!=0&&(a[j]-a[k])<d)
				cnt++;  
			if((a[j]-a[k])%d==0)
				b[j]=0;
			
				k++;
			
		}
		cnt--;
		b[i]=cnt;
		
	}
	for(int i=1;i<=t;i++)
	{
		cout<<b[i]<<"\n";
	}
	return 0;
}
