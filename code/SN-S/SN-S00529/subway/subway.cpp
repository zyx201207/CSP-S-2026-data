#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>PII;
int c,m,n,d,q;

const int N=510; 	


vector<int>w(N);
vector<vector<int>>line(N);
int main()
{
	freopen ("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
cin>>c>>m>>n>>d>>q;
for(int i=1;i<=m;i++)
	{
		cin >>w[i];
		
	}
	
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >>k;
		for(int j=0;j<k;j++)
		{
			int a,t;
			cin >>a>>t;
			line[i][j]=a;
		}
	}
	
	
		while(q--){
	
	}	
return 0;
 } 
