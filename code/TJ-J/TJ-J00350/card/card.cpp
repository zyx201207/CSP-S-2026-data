#include<iostream>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],b[N],c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int j=1;
		b[j]=a[i];
		for(int k=1;k<i;k++)
		{
			if(a[k]=a[i])
			{
				for(int l=k;l<=i;l++)
				{
					a[l]=0;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			if(a[k]!=0)
			{
				c[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
