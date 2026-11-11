#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pil pair<int,long long>
using namespace std;
int n,ww[500500],m,d,Q,k[505],x,y,c,a,t;
long long dis[505][505];
vector<pil>vv[500500];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			vv[a].emplace_back(mp(i,t));
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		//统计i号站台相关的最短路 
		for(pil j:vv[i])for(pil k:vv[i])if(j!=k){
			//两条线在这里交汇，求出它们之间的最短路！
			dis[j.fi][k.fi]=min(dis[j.fi][k.fi],j.se+k.se);
		}
	}
	//floyd n
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	if(i^j&&j^k&&k^i)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--){
		cin>>x>>y;
		long long ans=1e18;
		for(pil qwq:vv[x])for(pil pwp:vv[y])ans=min(ans,qwq.se+pwp.se+dis[qwq.fi][pwp.fi]);
		cout<<ans+ww[x]+ww[y]<<'\n';
	}
	return 0;
}//O((小于md^2) + n^3 + (小于qd^2))
/*
麻烦告诉我这个是青题还是绿题。
18:12 应该该致敬的经典都致敬了吧（）
*/
/*

X=' '=16分 xxx=24分*3
----------Petrichor - void(MournFinale)----------
（省略1min内容）（冰冰冰）
Part of my heart was left behind the day
I remember every time I smell the rain
Asking myself what atonement means
Why not this world takes me away to heaven
X XX XX XXX X XX XX XXX xxxxxxxxxxxx
X XX XX XXX X XX XX XXX xxxxxxxxxxxx
XX XX X XXX XX XX X XXX xxxxxxxxxxxx
XX XX X XXX XX XX X XXX xxxxxxxxxxxx
X X X X X X X X XXXXXX
X X X X X X X X XXXXXX
XXXXXXXXXXXXXXXXxxxxxxxxxxxxxxxxxxxxxxx
Pierces my heart,petrichor——————
X XX XX XXX X XX XX XXX xxxxxxxxxxxx
XX XX X XXX XX XX X XXX xxxxxxxxxxxx
XX XX X XXX XX XX X XXX xxxxxxxxxxxx
X XX XX XXX X XX XX XXX xxxxxxxxxxxx
X XX XX XXX X XX XX XXX xxxxxxxxxxxx
XX XX X XXX XX XX X XXX xxxxxxxxxxxx
Passes me grief petrichor
Rain penetrates the core of my body
And its coldness stirs up endless my regrets
In search of blue skies I'm lost my way
How far will the dark and damp journey continue
And I will pray forever even if it never ends......
*/
