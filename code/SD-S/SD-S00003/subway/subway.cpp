#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f; 
const int N=5e2+10;
int c,n,m,d,q;
int w[N];
int k[N];
int a[N][N],t[N][N];
void KApfme(){
	/*
	地铁口->站厅->站台 
	站台->站厅->地铁口
	题意理解了，感觉这个题不能很好做吧
	n给的是线路数量，站点数量是5e5 
	25个点，一个点4pts 
	*/
}
int ans=114514;
void dfs(int x,int y,int vis[20],int sum){
	if(x==y){
		sum+=w[y];
		sum+=w[x];
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				for(int kk=1;kk<=k[i];kk++){
					if(vis[a[i][kk]]!=1&&a[i][kk]!=x){
						vis[a[i][kk]]=1;
						dfs(a[i][kk],y,vis,sum+t[i][kk]);
					}
				}
				break;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	FAST
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
		int vis[20]={0};
		vis[x]=1;
		dfs(x,y,vis,0);
		cout<<ans<<'\n';
		ans=114514;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
