#include<bits/stdc++.h>
using namespace std;

long long a[100000000];

struct w{
	long long a,b;
}nb[10000000],ww[10000000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];	
	}
	long long k,x,y;
	while(q--)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>nb[i].a>>nb[i].b;
				
			}
		}
		cin>>x>>y;
		
	}
	return 0;
} 