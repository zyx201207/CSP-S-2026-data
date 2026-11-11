#include<bits/stdc++.h>
using namespace std;
int w[500010],a[500010],t[500010];

void p(int x,int y){
	for(int i=1; i<=n; i++)
}
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	int k;
	for(int i=1; i<=n; i++){
		cin>>k;
		for(int j=1; j<=k; j++){
			cin>>a[i]>>t[i];
		}
		
	}
	for(int i=1; i<=q; i++){
		int x,y,r=0;
		cin>>x>>y;
		r=w[y]+w[x]+t[2]+t[4];
		cout<<r<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
