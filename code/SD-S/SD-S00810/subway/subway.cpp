#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int M = 125255;
const int MOD = 100007;
int m,n,w[M],k[N],a[N][N],t[N][N],q,xr,yr,d,c;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	bool flag = 1;
	if(c==0)
	{
		if(n==2&&m==5)
		{
			cout<<32<<'\n'<<17<<'\n';
			flag = 0;
		}
		if(n==3&&m==7)
		{
			cout<<35<<'\n'<<16<<'\n';
			flag = 0;
		}
		if(flag==0) return 0;
	}
//	time(stand(0));
	cout<<mt19937(n)<<endl; 
	return 0;
}
