#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int MAXN = 1000005;
int C,T,n,k;
vector<int> e[MAXN];
int fa[MAXN],dep[MAXN],h[MAXN],pos,maxd[MAXN],liml1[MAXN],limr1[MAXN],liml2[MAXN],limr2[MAXN];
bool vis[MAXN];
void init()
{
	for(int i = 1;i <= n;i++)
		e[i].clear(),e[i].shrink_to_fit(),vis[i] = 0,maxd[i] = 0;
	pos = 0;
}
void dfs1(int u,int f)
{
	dep[u] = dep[f] + 1,fa[u] = f;
	for(auto v : e[u]) if(v != f) dfs1(v,u);
}
void getH()
{
	int p1 = 1,p2 = 1;
	dfs1(1,0);
	for(int i = 1;i <= n;i++) if(dep[i] > dep[p1]) p1 = i;
	dfs1(p1,0);
	for(int i = 1;i <= n;i++) if(dep[i] > dep[p2]) p2 = i;
	while(p2 != p1) h[++pos] = p2,p2 = fa[p2];
	h[++pos] = p1;
	for(int i = 1;i <= pos;i++) vis[h[i]] = 1;
}
void dfs2(int u,int f)
{
	for(auto v : e[u]) if(v != f) dfs2(v,u),maxd[u] = max(maxd[u],maxd[v] + 1);
}
void getD()
{
	for(int i = 1;i <= pos;i++)
		for(auto v : e[h[i]])
			if(!vis[v]) dfs2(v,h[i]),maxd[h[i]] = max(maxd[h[i]],maxd[v] + 1);
	//for(int i = 1;i <= n;i++)
	//	cerr<<maxd[i]<<endl;
	//cerr<<endl;
}
bool check(int w)
{
	int tk = k;
	for(int i = 1;i <= n;i++)
		if(!vis[i] && maxd[i] >= w) tk--;
	//cerr<<w<<endl;
	for(int i = 1;i <= pos;i++)
	{
		if(maxd[h[i]] >= w) liml1[i] = limr1[i] = i;
		else liml1[i] = i + w - maxd[h[i]],limr1[i] = i - w + maxd[h[i]];
		liml2[i] = liml1[i],limr2[i] = limr1[i];
		//cerr<<w<<" "<<h[i]<<" "<<liml1[i]<<" "<<limr1[i]<<endl;
	}
	for(int i = 2;i <= pos;i++)
		liml1[i] = min(liml1[i],liml1[i - 1]),limr1[i] = max(limr1[i],limr1[i - 1]);
	for(int i = pos - 1;i;i--)
		liml2[i] = min(liml2[i],liml2[i + 1]),limr2[i] = max(limr2[i],limr2[i + 1]);
	//cerr<<tk<<" "<<limr1[pos]<<liml1[pos]<<endl;
	if(max(1,limr1[pos] - liml1[pos] + 1) <= tk) return 1;
	for(int i = 1;i < pos;i++)
		if(max(1,limr1[i] - liml1[i] + 1) + max(1,limr2[i + 1] - liml2[i + 1] + 1) <= tk)
		{
			//cerr<<i<<endl;
			//cerr<<limr1[i]<<liml1[i]<<limr2[i + 1]<<liml2[i + 1]<<endl;
			return 1;
		}
	return 0;
}
void solve()
{
	scanf("%d%d",&n,&k);
	init();
	for(ll i = 1;i < n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
	}
	getH();
	getD();
	int pl = 0,pr = n;
	while(pl <= pr)
	{
		int mid = pl + pr >> 1;
		if(check(mid)) pr = mid - 1;
		else pl = mid + 1;
	}
	printf("%d\n",pl);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--) solve();
	return 0;
}
/*
Which crew flyer than us riddle me that
We don't need to do nothing let them react
You know I could slay the whole city with that
We taking over the night because I'm pretty in black
Every thing we do got a runway with it
Walk so mean like mind your business
Look so sharp Hatori Hanzon Line
Then I hit'em with the blue steel Mugatu get it
Weighed in gold
My Words can never be
In all the realm of eternity
Let your words and couture
Drape in colors and desire
on this night of fate
I just turn Met Gala to an X GALA
Yeah I could dress casually naturally
Anything becomes a masterpiece
Look out the kits match the tee
Every single day becomes a fashion week
It's like art fashionable lover
I'm like a narc cuz I'm always on the cover
Hit'em with the pose and the swag too official
Only Ellen I know is the mag what's the issue.
Pretty boys walk like this
Pretty boys talk like this
Couple Chrome plates on wrist
I mean who else do you know put it on like this
If you don't get it that's not my problem
changing my hair like my last name Rodman
Top five with the drip top to buttom
Anything that we rock they'll be talking about it
Turn the hallway to the cat walk
Turn the sidewalk to the runway
Everything's a photoshoot that part
Paparazzi got my outfit on the front page
Rolled up in it windows tinted
Can't see through it but they know who's in it
Shaking up the spot
Looking stone cold shiver and we
Shine through the dark like a snow globe glitter
I represent the XGALX
Man I told you I'ma turn this Met to the X GALA
Watch the step
The all hell the X
Here to crash the party
So get out my way
All mechanic sweety sxxy savage
And the finest garment hanging down my waist
Ooh all my ladies walk this way
To All my haters watch me slay
Bionic all mechanic
domo arigato Mr Robot
*/