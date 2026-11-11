#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=405;
const int N2=5e5+10;
int n,m,d,q;
int s[N][N];
int w[N];
int a[N],t[N];
int w2[N2],t2[N2];
void fun1(){
	for(int i=1;i<=m;i++){
		cin>>w2[i];
	}
	int k;
	cin>>k;
	for(int j=1;j<=k;j++){	
		int v; 
		cin>>v>>t2[v];
	}
	while(q--){
		int u,v;
		cin>>u>>v;
//		cout<<s[u][v]<<' ';
		cout<<t2[u]+t2[v]+w2[u]+w2[v]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin>>c;
	cin>>n>>m>>d>>q;
	if(n==1&&m>400){
		fun1();
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				s[i][j]=0x3f3f3f3f3f3f3f3f;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(j!=l){
					int u=a[j];
					int v=a[l];
					s[u][v]=min(t[j]+t[l],s[u][v]);
				}
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	
	while(q--){
		int u,v;
		cin>>u>>v;
//		cout<<s[u][v]<<' ';
		cout<<s[u][v]+w[u]+w[v]<<'\n';
	}
	return 0;
}