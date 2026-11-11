#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
#define pb push_back
#define endl '\n'
#define kg ' '
#define CLOSE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void Case1();
void Case2();
void Case3();
void Case4();
int fnd(int x);
void mrg(int x,int y);

const int N1=1106;

int g[N1][N1],w[N1],s[N1],c,n,m,d,q;

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	CLOSE

	cin>>c>>n>>m>>d>>q;
	
	if(c<=8) Case1();
	else if(c>=9&&c<=11) Case2();
//	else if(c>=12&&c<=19) Case3();
	else Case1();
	
	return 0;
}

int fnd(int x){
	if(x!=s[x]) return x=fnd(x);
}

void mrg(int x,int y){
	x=fnd(x);
	y=fnd(y);
	if(x!=y) s[x]=y;
}

void Case1(){
	
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m+n;i++) g[i][i]=0;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int k=1;k<=n;k++){
		int x;
		cin>>x;
		for(int i=1;i<=x;i++){
			int vv,ww;
			cin>>vv>>ww;
			g[k+m][vv]=g[vv][k+m]=ww;
		}
	}
	
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	
	while(q--){
		int X,Y;
		cin>>X>>Y;
		cout<<w[X]+w[Y]+g[X][Y]<<endl;
	}
	
	return;
}

void Case2(){
	
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++) g[i][i]=0;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int k=1;k<=n;k++){
		int x;
		cin>>x;
		if(x==1) continue;
		int v1,w1,v2,w2;
		cin>>v1>>w1>>v2>>w2;
		g[v1][v2]=g[v2][v1]=w1+w2;
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	
	while(q--){
		int X,Y;
		cin>>X>>Y;
		cout<<w[X]+w[Y]+g[X][Y]<<endl;
	}
	
	return;
}

void Case3(){
	
	int T=0;
	
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++) g[i][i]=0;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int k=1;k<=n;k++){
		int x;
		cin>>x;
		int v0,v1;
		for(int i=1;i<=x;i++){
			cin>>v1>>T;
			if(i!=1) mrg(v1,v0);
			v0=v1;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			int X=fnd(i),Y=fnd(j);
			if(i!=j&&X==Y) g[i][j]==T;
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	
	while(q--){
		int X,Y;
		cin>>X>>Y;
		cout<<w[X]+w[Y]+g[X][Y]<<endl;
	}
	
	return;
}

void Case4(){
	
	int num=0x3f3f3f3f3f3f3f3f;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int k=1;k<=n;k++){
		int x;
		cin>>x;
		int v0,v1,v2,v3;
		if(x==2){
			cin>>v0>>v1>>v2>>v3;
			num=min(num,v1+v3);
		}
	}
	
	if(n==1) cout<<w[1]*2<<endl;
	else if(n==2) cout<<w[1]+w[2]+num<<endl;
	
	
	return;
}
