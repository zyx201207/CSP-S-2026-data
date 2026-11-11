#include<bits/stdc++.h>
using namespace std;
int w[500009],x[100009],y[100009];
int b[500009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	int a[n+1][k+1],t[n+1][k+1];
	for(int x=1;x<=n;x++){
		for(int i=1;i<=k;i++){
			cin>>a[x][i]>>t[x][i];
			b[i]=x;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=0;
		ans+=w[x[i]];
		ans+=t[b[x[i]]][x[i]];
		for(int j=x[i];j<y[i];j++){
			if(b[j]!=b[j+1]){
				ans+=t[b[j]][j+1];
				ans+=t[b[j+1]][j+1];
			}
		}
		ans+=t[b[y[i]]][y[i]];
		ans+=w[y[i]];
		cout<<ans<<endl;
	}
	return 0;
}
