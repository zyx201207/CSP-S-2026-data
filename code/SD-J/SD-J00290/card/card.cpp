#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[500005],b[500005],c[500005];
bool zj[300005];
int d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int q=1;q<=n;q++)
	{
		for(int i=q;i<=n;i++)
		{
			b[i]=a[i];
			if(c[a[i]])
			{
				for(int j=c[a[i]];j<i;j++){
					b[j]=0;c[b[j]]=0;
				}
			}
			c[b[i]]=i;
		}
		for(int i=q;i<=n;i++)
		{
			if(b[i]!=0){
				if(zj[b[i]]==0){
					d[b[i]]+=1;zj[b[i]]=1;cout<<b[i]<<' ';
				}
			}
		}
		cout<<endl;
		memset(zj,0,sizeof(zj));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<' ';
	return 0; 
 } 
