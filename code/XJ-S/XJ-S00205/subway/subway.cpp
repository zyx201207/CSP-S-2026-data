#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q;
int w[maxn];
int t[maxn];


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,f;
			cin>>y>>f;	
			t[y]=f;
		}
	}		
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x]+t[y]<<endl;
	}
	
	return 0;
}

