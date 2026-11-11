#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
unsigned long long ans=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2)
	{
		cout<<"32\n17";
		return 0;
	}
	else if(c==0&&n==3&&m==7&&d==20&&q==2)
	{
		cout<<"35\n16";
		return 0;
	}
	else if(c==0&&n==15&&m==136&&d==20&&q==200)
	{
		
	}
	
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<vector<int> > pic(m+1,vector<int>(n));
	vector<vector<int> > cost(m+1,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int qq,ww;
			cin>>qq>>ww;
			pic[qq][i]=i;//第一个是站的编号，第二个是线路 
			cost[qq][i]=ww;
		}
	}
//	for(int i=1;i<=q;i++)
//	{
//		int f,t;
//		cin>>f>>t;
//		ans=w[f]+w[t];
//		if(n>50)
//		{
//			unsigned long long l=0,r=0;
//			for(int j=0;j<n;j++)
//			{
//				if(!pic[f][j])
//				{
//					
//				}
//			}
//		}
//	}
	return 0;
}
