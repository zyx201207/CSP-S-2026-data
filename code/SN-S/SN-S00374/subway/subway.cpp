//刘曌珩   SN-S00374  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int ans=0,o=0,p=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int t=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x) t++,o=j;
				if(a[i][j]==y) t++,p=j;
			}
			if(t==2){
				ans=i;
				break;
			}
		}
		if(ans!=0&&o!=0&&p!=0){
			cout<<w[x]+w[y]+t[ans][o]+t[ans][p]<<"\n";
		}
		else cout<<w[x]+w[y]+t[1][1]+t[1][2]+t[2][1]+t[2][2]<<"\n";
	}
	return 0;
}
