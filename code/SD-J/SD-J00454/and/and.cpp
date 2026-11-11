#include<bits/stdc++.h>
using namespace std;
struct node{
	int ls[35];
	int num;
};
node a[200005];
int now=0;int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i].num=x;
		int pos=0;
		while(x!=0)
		{
			pos++;
			a[i].ls[pos]=x%2;
			x/=2;
		}
		k=max(k,pos);
	}
	for(int i=1;i<=k;i++)
			{
				int t=0;
				for(int j=1;j<=n;j++)
				{
					t+=a[j].ls[i];
					cout<<a[j].ls[i]<<endl;
				}
				if(t==m)
				{
					ans+=w;
				}
				w*=2;
			}
			cout<<ans<<endl;
	cout<<endl;
	return 0;
 } 
