#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],ans[1000010],cd;

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
		map<long long,long long>ma,pd;
		cd=0;
		for(int j=i;j<=n;j++)
		{
			if(ma[a[j]]>0)
			{
				for(int k=ma[a[j]];k<=cd;k++)
				{
					ma[pd[k]]=0;
					pd[k]=0;
				}
			}
			pd[++cd]=a[j];
			ma[a[j]]=cd;
//			for(int k=1;k<=cd;k++)
//			{
//				cout<<pd[k]<<" ";
//			}
//			cout<<endl;
		}
		for(int j=1;j<=cd;j++)
		{
			if(pd[j])
			{
				ans[pd[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

