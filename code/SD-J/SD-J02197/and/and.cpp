#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100001],d[100001],d1=1,ans=0,k=0,pns;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	cin>>c[i];
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(ans<c[j])
			{
				ans=c[j];
				k=j;
			}			
		}
		c[k]=0;
		d[d1]=ans;
		ans=0;
		d1++;
	}
	pns=d[1];
	for(int i=2;i<=b;i++)
	pns=pns&d[i];
	cout<<pns<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
