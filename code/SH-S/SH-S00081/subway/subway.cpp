#include<bits/stdc++.h>
using namespace std;
int w[500010]={};
int a[510][510]={};
int t[510][510]={};
int jhx[100010]={};
int jhy[100010]={};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c=0;int n=0;int m=0;int d=0;int q=0;int ki=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int j=0;j<n;j++)
	{
		cin>>ki;
		for(int p=0;p<ki;p++)
		{
			cin>>a[j][p]>>t[j][p];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>jhx[i]>>jhy[i];
	}
	cout<<"end";
	return 0;
} 
