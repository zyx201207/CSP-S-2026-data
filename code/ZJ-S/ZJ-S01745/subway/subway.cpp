  #include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int dp[550][550]; 
int v[500050][25];
int p[500050][25];
int w[500050];
int k[550];
vector<int> a[550],t[550];
int _,n,m,d,q;
int Ans[100010];
struct query{int x,y,pos;}qp[100010];
bool cmp(query a,query b){return a.x<b.x;}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			v[x][++v[x][0]]=i;
			p[x][v[x][0]]=j;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qp[i].x>>qp[i].y,qp[i].pos=i;
		if(qp[i].x>qp[i].y) swap(qp[i].x,qp[i].y);
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i]=0;
	sort(qp+1,qp+q+1,cmp);
	int pos=q;
	for(int tot=m;tot>=1;tot--){
		int rq=pos,lq;
		while(pos>=1&&qp[pos].x==tot) pos--;
		lq=pos+1;
		for(int i=1;i<=v[tot][0];i++)
			for(int j=1;j<=v[tot][0];j++){
				dp[v[tot][i]][v[tot][j]]=min(dp[v[tot][i]][v[tot][j]],t[v[tot][i]][p[tot][i]]+t[v[tot][j]][p[tot][j]]);
				dp[v[tot][j]][v[tot][i]]=dp[v[tot][i]][v[tot][j]];
			}
		for(int k=1;k<=v[tot][0];k++)
			for(int i=1;i<=v[tot][0];i++)
				for(int j=1;j<=n;j++){
					dp[v[tot][i]][j]=min(dp[v[tot][i]][j],dp[v[tot][i]][v[tot][k]]+dp[v[tot][k]][j]);
					dp[j][v[tot][i]]=dp[v[tot][i]][j];
				}
		for(int k=lq;k<=rq;k++){
			int ans=1e18;
			int x=qp[k].x,y=qp[k].y;
			for(int i=1;i<=v[x][0];i++)
				for(int j=1;j<=v[y][0];j++)
					ans=min(ans,t[v[x][i]][p[x][i]]+t[v[y][j]][p[y][j]]+dp[v[x][i]][v[y][j]]);	
			Ans[qp[k].pos]=ans+w[x]+w[y];
		}
	}
	for(int i=1;i<=q;i++) cout<<Ans[i]<<endl;
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
饭堂了…… 
哎不是地铁怎么是往返的 
*/

