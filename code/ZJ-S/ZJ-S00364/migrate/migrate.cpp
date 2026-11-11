#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e6+10;
int C,T,ans;
int n,d;
long long x[N];
int minn[5010][5010];
void dfs(int t,int yx,int xx,int yy){
	if(t>minn[yx][yy]) return;
	if(ans>2) return ;
	if(xx==yy){
		if(t==minn[yx][yy]) ans++;
		return ;
	}
	for(int i=xx+1;i<=yy;i++){
		if(x[i]-x[xx]<=d){
			dfs(t+1,yx,i,yy);
		}
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(C<=2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					minn[i][j]=1e9;
					if(i==j) minn[i][j]=0;
				}
			}
			int TT=0;
			for(int i=1;i<=n;i++){
				int lst=i;
				for(int j=i+1;j<=n;j++){
					while(1){
						if(x[j]-x[lst]<=d){
							minn[i][j]=minn[i][lst]+1;
							break;
						}
						lst++;
						if(lst>j) break;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=0;
					dfs(0,i,i,j);
					if(ans==2){
						TT++;
//						cout<<i<<' '<<j<<'\n';
					}
				}
			}
			cout<<TT<<'\n';
			continue;
		}
		if(C==11||C==12){
			int t=0;
			for(int i=2;i<=n;i++){
				if(x[i]-x[1]<=d){
					t++;
				}else break;
			}
			if(t<=1){
				cout<<0<<'\n';
				continue;
			}
			ans=0;
			for(int i=1;i<=n;i++){
				if(i+t+t-1<=n) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
	}
//	cout<<clock()<<"ms";
	return 0;
}
/*
11 1
9 3
2 3 4 5 6 7 8 9 10
*/ 
