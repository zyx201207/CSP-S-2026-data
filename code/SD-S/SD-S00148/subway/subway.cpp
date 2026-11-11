#include<bits/stdc++.h>
using namespace std;

const int N=5e2+5;
const int M=1e3+5;
int c,n,m,d,q;
int w[M],k[N];
int f[M][M];
void add(int x,int y,int z){
	f[x][y]=z;
	return ;
}
void init(){
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f3f3f3f,sizeof f);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			add(i+m,a,t);
			add(a,i+m,t);
		}
	}
	for(int i=1;i<=n+m;i++){
		f[i][i]=0;
	}
	return;
} 

long long ask(int l,int r){
	long long ans=w[l]+w[r];
	ans+=f[l][r];
	return ans; 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<ask(l,r)<<"\n";
	}
	return 0;
}

