#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=1e3;
int c,t;
ll n,d;
ll a[N];
struct aox{
	int sum,t;
}b[M][M];
void dfs(int x,int j,int cnt){
	if(x!=j&&b[j][x].t){
		if(b[j][x].t<=cnt)b[j][x].sum++;
		else{
			b[j][x].sum=1;
			b[j][x].t=cnt;
		}
	}
	if(x!=j&&!b[j][x].t){
		b[j][x].sum++;
		b[j][x].t=cnt;
	}
	if(j==n)return;
	for(int ij=j+1;ij<=n;ij++){
		if(a[ij]-a[j]<=d)dfs(x,ij,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n/2;i++)dfs(i,i,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++){
				if(b[i][j].sum==2)ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}