#include<bits/stdc++.h>
using namespace std;
int m[2000001];
long long int s,p,ma,n,d;
int tt(int x,int y,int z,int dd,int t)
{
	int i,j;
	if(t>ma)
	return 0;
	for(i=y;i>=z+1;i--)
	{
		if(m[i]-m[z]<=dd)
		{
			if(i==y)
			{
				if(t==ma&&t!=m[y]-m[x])
				{
					if(p<1) 
					p=1;
					else if(p>=1)
					p=2;
				}
				else if(t<ma)
				{
					p=0;
					ma=t;
				 } 
				return 0;
			}
			tt(x,y,i,d,t+1); 
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,k,qq;
	cin>>c>>k;
	for(qq=0;qq<k;qq++)
	{
		long long int i,j;
		cin>>n>>d;
		s=0;
		for(i=0;i<n;i++)
		{
			cin>>m[i];
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+3;j<n;j++)
			{
				ma=m[j]-m[i];
				p=0;
				tt(i,j,i,d,1);
				if(p==1)
				s++;
			}
		 }
		cout<<s<<endl;
	}

}
