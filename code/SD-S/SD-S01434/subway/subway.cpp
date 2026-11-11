#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
const int MAXN=510;
const int MAXM=500010;
ll w[MAXM];
int k[MAXN];
int a[MAXN][MAXM];
int t[MAXN][MAXM];
ll sum=0;

ll solve(int x,int y,int xl){
	if(x==y){
		return sum;
	}
	int nowx,nowp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x&&i!=xl){
				nowx=i;
				nowp=a[i][j];
				break;
			} 
		}
	}
	bool isok=false;
	for(int j=1;j<=k[nowx];j++){
		if(a[nowx][j]==y){
			sum+=t[nowx][j];
			return sum;
		}else{
			solve(j,y,nowx);
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//init();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		sum=0;
		ans+=solve(x,y,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
