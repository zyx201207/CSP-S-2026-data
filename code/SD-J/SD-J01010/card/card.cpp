#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],t[N];
long long tt[N]={};
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			t[j]=a[j];
			for(int k=i;k<j;++k)
			{
				if(t[k]==t[j])
				{
					for(int l=k;l<j;++l) t[l]=0;
				}
			}	
		}
		for(int k=i;k<=n;++k)
		if(t[k]!=0) ++tt[t[k]];
	}
	for(int i=1;i<=m;++i) cout<<tt[i]<<" ";
	fclose(stdin);fclose(stdout);
	return 0;
}
