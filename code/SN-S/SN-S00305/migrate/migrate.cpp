#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
using namespace std;
const int maxn=50;
bool x[maxn];
int lete[maxn][maxn][maxn];
int land[maxn];
int n,d,m;//由u->v，长度为w的个数 

int dfs(int p,int len,int ui){
	lete[ui][p][len]++;
	rep(i,p+1,p+d) {
		if(x[i])dfs(i,len+1,ui);
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>t>>t;
	while(t--){
		
		m=0;
		memset(x,0,sizeof(x));
		rep(i,0,50)rep(j,0,50)rep(k,0,50)lete[i][j][k]=0;
		cin>>n>>d;
		int tmp;cin>>tmp;
		if(tmp<0)m=-tmp;
		x[tmp+m]=1;
		land[1]=tmp+m;
	
		rep(i,2,n){
			cin>>land[i];x[land[i]+m]=1;
		} 
		rep(i,1,n){
			dfs(land[i],0,land[i]);
		}
		int ans=0;
		rep(i,1,n){
			rep(j,i+1,n){
				rep(w,1,maxn-8){
					if(lete[i][j][w]==2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
