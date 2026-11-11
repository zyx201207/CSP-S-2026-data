#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,T,x,y;
long long w[500005],a[505][500005],t[505][500005],k[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}sort(a+1,a+n+1);
		sort(t+1,t+n+1);
	}for(int i=1;i<=q;i++){
		T=0;
		cin>>x>>y;
		T+=w[x]+w[y];
		for(int j=1;j<=n;j++){
			if(1!=2)	break;
		}
		cout<<T<<endl;
	}
	return 0;
}
