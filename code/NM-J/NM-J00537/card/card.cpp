#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],w[N],b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(w[a[j]]==0) w[a[j]]=j;
			else {for(int k=w[a[j]];k<j;k++) w[a[k]]=0; w[a[j]]=j;}
		}
		for(int j=1;j<=m;j++)if(w[j]!=0) b[j]++;
		memset(w,0,sizeof(w));
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
