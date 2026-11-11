#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n[10001],d[10001],a[1000][200001],f,df,cnt=0;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++)
		{
		cin>>a[i][j];
		}
	}
	for(int i=0;i<t;i++)
	{
		f=a[i][1]-a[i][0];
		df=d[i]/f;
		int dff=df*f;
		for(int k=0;k<n[i];k++)
		{
			int kk=f*(n[i]-k);
			if(kk%dff!=0)
			{
				if(kk/df==1)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
	

