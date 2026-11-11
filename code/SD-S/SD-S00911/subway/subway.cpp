#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e2+10;
int w[N];
int a[N][N],t[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int sum=0;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<=n;i++){
		int k;;
		cin>>k;
		for(int j=1;j<=k;k++){
			cin>>a[i][j]>>t[i][j];
			sum+=a[i][j]+t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		cout<<sum<<"\n"; 
	}
	return 0;
}

