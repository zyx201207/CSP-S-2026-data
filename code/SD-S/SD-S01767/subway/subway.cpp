#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main()
{
	//doubao AI
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T,n,m,d,q;
	cin>>T>>n>>m>>d>>q;
	int w[n+10];
	int fl[m+10][m+10][4];
	int dian[m+10][m+10];
	memset(dian,0x3f,sizeof dian);
	//doubao AI
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int N;
		cin>>N;
		N--;
		int k,l,k2,l2;
		cin>>k>>l;
		dian[i][k]=l;
		while(N--)
		{
			cin>>k2>>l2;
			fl[k][k2][1]=i;
			fl[k][k2][2]=0;
			k=k2;
			l=l2;
			dian[i][k]=l;
		}
	}//doubao AI
	for(int i=1;i<=q;i++)
	{
		int qp,db;
		cin>>qp>>db;
		
		int min1=INT_MAX,min2=INT_MAX;
		for(int j=1;j<=m;j++)
		{
			cout<<dian[j][qp]<<" ";
			min1=min(dian[j][qp],min1);
		}
		cout<<w[qp]<<" "<<w[db]<<" "<<min1<<" "<<min2<<endl;
		//cout<<w[qp]+w[db]+min1+min2<<endl;
	}
	return 0;
}//doubao AI
