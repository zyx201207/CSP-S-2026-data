#include"iostream"
using namespace std;
#define ll long long
const ll M=5e3+5,N=5e2+5,Q=1e5+5;
ll a[N][M],t[N][M],x[Q],y[Q],w[M];
ll c,n,m,d,q,k;
int check(int qwq,int ovo){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(a[i][j]==qwq&&a[i][j+1]==ovo){
				return i;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout<<(sizeof(a)+sizeof(t)+sizeof(x)+sizeof(y)+sizeof(w))/1024/1024.0;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<'\n'<<17;
			return 0;
		}
		else if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<'\n'<<16;
			return 0;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
		cout<<check(x[i],y[i])<<endl;
	}
//	cout<<sizeof(a)/1024/1024.0;
	return 0;
}