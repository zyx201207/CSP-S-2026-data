#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int M=3e3+5;
int n,m;
int a[N],v[M],idx[M];
bool k[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(!k[a[i]])
		{
			k[a[i]]=1;
			v[a[i]]++;
			idx[a[i]]=i; 
		}
		else
		{
			for(int j=idx[a[i]];j<i;j++)
			{
				a[++n]=a[j];
				idx[a[j]]=n;
				k[a[j]]=0;
				a[j]=-1;
			}
			k[a[i]]=1;
			v[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<v[i]<<" ";
	return 0;
}
