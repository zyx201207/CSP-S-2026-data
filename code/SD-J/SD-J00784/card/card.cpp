#include<bits/stdc++.h>
using namespace std;
int a[1000010],tong[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int>vc;
		for(int j=i;j<=n;j++)
		{
			bool flag=false;
			for(int k=0;k<vc.size();k++)if(vc[k]==a[j]){flag=true;break;}
			if(flag)
			{
				while(!vc.empty()&&vc.back()!=a[j])vc.pop_back();
			}
			else vc.push_back(a[j]);
		}
	//	cout<<i<<":";
		for(int j=0;j<vc.size();j++)tong[vc[j]]++;
	//	cout<<endl;
	}
	for(int i=1;i<=m;i++)
		cout<<tong[i]<<" ";
}
