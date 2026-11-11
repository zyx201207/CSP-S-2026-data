#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,a[500100],va[300100],bj[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
//		cout<<va[3]<<endl;
		int v[300100]={};
		int r=0;
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]] and v[a[j]]<=r and bj[v[a[j]]]==a[j])
			r=v[a[j]];
			else
			{
				bj[++r]=a[j];
				v[a[j]]=r;
			}
		}
		for(int j=1;j<=r;j++)
		{
			va[bj[j]]++;
//			cout<<bj[j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	cout<<va[i]<<" ";
//	cout<<1;
	return 0;
 } 
