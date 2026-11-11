#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],c[500001],ans[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int top=0;
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{

				for(int k=1;k<=top;k++)
				{
					if(c[k]==a[j])
					{
					top=k-1;	
				//	cout<<"114514";
					}
				}
				top++;
				c[top]=a[j];
		}
		for(int j=1;j<=top;j++)
		{
			ans[c[j]]++;
			//cout<<c[j]<<" ";
		}
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
