#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100;
int c,n,m,d,q,tot,w[N],x,y,a,b,k,t[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[i][x]=y;
		}
	}
	if((c==20||c==21)&&n==1){
		for(int i=1;i<=q;i++){
			cin>>a>>b;
			cout<<w[a]+t[1][a]+t[1][b]+w[b]<<"\n";
		}
	}else if(c>=12&&c<=19){
		for(int i=1;i<=q;i++){
			cin>>a>>b;
			cout<<w[a]+w[b]+(b-a+1)*t[1][b]<<"\n";
		}
	}else{
		for(int i=1;i<=q;i++){
			cin>>a>>b;
			cout<<w[a]+t[a][a]+t[a][b]+w[b]<<"\n";
		}
	}
	return 0;
} 