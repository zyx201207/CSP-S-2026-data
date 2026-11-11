#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=505,M=5e5+5;
int read(){
	int ans=0;
	char ch=getchar();
	while(ch<='9'&&ch>='0'){
		ans*=10;
		ans+=ch-'0';
		ch=getchar();
	}
	return ans;
}
int ma[N][N];
vector<pii>lines[M];
int n,m,d,c[M],k[N];
vector<int>a[N],t[N]; 
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Q=0,cc=0;
	cin>>cc>>n>>m>>d>>Q;
	//cout<<n;
	memset(ma,0x3f,sizeof(ma));
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];//cout<<1;
		getchar();
		for(int j=0;j<k[i];j++){//id
			int aa=read(),tt=read();
			a[i].push_back(aa),t[i].push_back(tt);
			lines[a[i][j]].push_back({i,j}); //line+id
		}
	}
	
	for(int i=1;i<=m;i++){
		for(pii j:lines[i]){
			for(pii k:lines[i]){//枚举站点地铁线建边 
				if(j.fi==k.fi)continue;
				ma[j.fi][k.fi]=ma[k.fi][j.fi]=min(ma[j.fi][k.fi],t[j.fi][j.se]+t[k.fi][k.se]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<ma[i][j]<<' ';
		cout<<'\n';
	}*/
	for(int i=1;i<=n;i++)ma[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
			}
		}
	} 
	
	while(Q--){
		int xx,yy;
		cin>>xx>>yy;
		int ans=1e18;
		for(pii i:lines[xx]){
			for(pii j:lines[yy]){
				ans=min(ans,ma[i.fi][j.fi]+c[xx]+c[yy]+t[i.fi][i.se]+t[j.fi][j.se]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

