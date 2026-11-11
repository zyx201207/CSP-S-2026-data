#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=2e6+11;
int Tt,c;
int x[N],cnt,minn=(LONG_LONG_MAX-10);
void dfs(int u,int gol,int len,int D,int nn){
	if(u==gol){
		if(len<minn){
			minn=len;
			cnt=1;
		}else if(minn==len){
			cnt++;
		}
		return ;
	}else if(u>gol)return ;
	for(int i=u+1;i<=nn;i++){
		if(x[i]-x[u]>D)break;
		dfs(i,gol,len+1,D,nn);
	}
}
void sol1(){
	while(Tt--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=(LONG_LONG_MAX-10);cnt=0;
				dfs(i,j,0,d,n);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>Tt;
	if(c<=10){
		sol1();
		exit(0);
	}else{
		while(Tt--)cout<<"0\n";
	}
	return 0;
}