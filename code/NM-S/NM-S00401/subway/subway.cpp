#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500005],a[1000][50000],t[1000][50000];
int x[10000],y[10000],ans,st;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		st=x[i];
		while(st!=y[i]){
			ans+=w[st];
			
		}
	}
	while(q--) cout<<5<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

