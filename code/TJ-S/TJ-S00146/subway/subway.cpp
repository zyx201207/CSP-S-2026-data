#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100000];
long long t[100000][100000],a[100000][100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		int k=1;
		for(int j=1;j<=ki;j++){
			cin>>a[j][k]>>t[j][k];
			k++;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long s=0;
		s=s+w[x]+t[x][1]+t[x][2]+w[y];
		cout<<s<<"\n";
	}
	return 0;
}

