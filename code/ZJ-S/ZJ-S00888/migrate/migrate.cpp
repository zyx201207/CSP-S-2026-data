#include<bits/stdc++.h>
#define rep(n,l,r) for(int n=l;n<=r;n++)
#define rep0(n,r) for(int n=0;n<=r;n++)
#define rep1(n,r) for(int n=1;n<=r;n++)

#define N 2000002
#define int long long
 
using namespace std;

int n,d,x[N],tag[N];
int in[N],out[N];

int ccc=0,minn=2147483647,de=0;
bool vis[1234];
void dfs(int i,int l){
//	cout<<i<<'\n';
	if(i==de){
		if(l<minn)ccc=1,minn=l;
		else if(l==minn)ccc++;
	}
	int cur=i+1;
	while(cur<=n&&x[cur]-x[i]<=d)dfs(cur,l+1),cur++;
}

bool check(int i,int j){
	minn=2147483647;
	memset(vis,0,sizeof vis);
	de=j;
	dfs(i,0);
	return ccc==2;
}

void f1(){
	int ret=0;
	cin>>n>>d;
	rep1(i,n)cin>>x[i];
	if(n<=3){
		cout<<0;
		return;
	}
	rep(j,2,n)
		rep(i,1,j-1)
			if(check(i,j))ret++;
	cout<<ret<<'\n';
}

void f2(){
	cin>>n>>d;
	rep1(i,n)cin>>x[i];
	int delta=x[2]-x[1];
	int qwe=d/delta;
//	cout<<"-----   "<<n<<' '<<d<<' '<<delta<<'\n';
	if(qwe<=1)cout<<0<<'\n';
	else{
		int asd=max(0ll,n-2*qwe+1);
		cout<<asd<<'\n'; 
	} 
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12)f2();
		else f1();
	}
	
	return 0;
}
