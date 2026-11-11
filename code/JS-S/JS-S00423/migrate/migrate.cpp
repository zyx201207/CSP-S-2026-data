#include <bits/stdc++.h>
using namespace std;
#define FIO(filename) freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + (c ^ '0');
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <typename T>
void chkmx(T &x,T y){x=max(x,y);}
template <typename T>
void chkmn(T &x,T y){x=min(x,y);}
using ll = long long;
const ll inf=1e18;
void solve()
{
	int n;ll d;
	read(n,d);
	vector<ll>X(n+5);
	for(int i=1;i<=n;i++)
		read(X[i]);
	X[n+1]=5*inf;
	vector<int>nxt(n+5,n+1);
	for(int i=1;i<=n;i++)
		nxt[i]=upper_bound(X.begin()+1,X.begin()+n+2,X[i]+d)-X.begin()-1;
	// vector<vector<vector<int>>>f(n+5,vector<vector<int>>(n+5,vector<int>(3)));
	// for(int j=0;j<=n;j++)
	// 	f[n+1][j][0]=f[n+1][j][1]=f[n+1][j][2]=n+1;
	// for(int i=n;i>=1;i--)
	// {
	// 	f[i][0][0]=i;
	// 	f[i][0][1]=0;
	// 	f[i][0][2]=0;
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		int p=nxt[i];
	// 		chkmx(f[i][j][0],f[p][j-1][0]);
	// 		chkmx(f[i][j][1],f[p][j-1][1]);
	// 		// if(f[p][j-1][0]>1)
	// 		// 	chkmx(f[i][j][1],f[p][j-1][0]-1);
	// 		if(p>1&&j>1)
	// 			chkmx(f[i][j][1],f[p-1][j-1][0]);
	// 		chkmx(f[i][j][2],f[p][j-1][2]);
	// 		// if(f[p][j-1][1]>1)
	// 		// 	chkmx(f[i][j][2],f[p][j-1][1]-1);
	// 		// if(f[p][j-1][1]>2)
	// 		// 	chkmx(f[i][j][2],f[p][j-1][0]-2);
	// 		if(p>1&&j>1)
	// 			chkmx(f[i][j][2],f[p-1][j-1][1]);
	// 	}
	// }ll ans=0;
	// for(int u=1;u<=n;u++)
	// {
	// 	vector<int>s(n+5);
	// 	for(int j=1;j<=n;j++)
	// 		cout<<u<<' '<<j<<' '<<f[u][j][0]<<' '<<f[u][j][1]<<' '<<f[u][j][2]<<'\n';
	// 	for(int j=2;j<=n;j++)
	// 	{
	// 		if(f[u][j][0]==f[u][j][1]&&
	// 			(j<=2||f[u][j][2]<f[u][j][0]))
	// 		{
	// 			if(j==2)
	// 			{
	// 				s[f[u][j][0]]++;
	// 				s[f[u][j][0]+1]--;
	// 			}
	// 			else
	// 			{
	// 				s[f[u][j][2]]++;
	// 				s[f[u][j][0]+1]--;
	// 			}
	// 		}
	// 	}
	// 	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	// 	for(int i=1;i<=n;i++)
	// 		ans+=s[i]>0;
	// }
	// for(int i=1;i<=n;i++)
	// 	cout<<nxt[i]<<' ';
	// cout<<'\n';
	vector<vector<int>>f(n+1,vector<int>(n+1,n+1));
	for(int u=1;u<=n;u++)
	{
		int t=u;
		int cnt=0;
		f[u][u]=0;
		while(t!=nxt[t])
		{
			t=nxt[t];
			f[u][t]=++cnt;
		}
		for(int j=t-1;j>=u;j--)
			chkmn(f[u][j],f[u][j+1]);
	}
	ll ans=0;
	for(int u=1;u<=n;u++)
	{
		for(int v=u+1;v<=n;v++)
		{
			if(f[u][v]>n)continue;
			vector<int>vec;
			int t=u;
			while(t<=v)
			{
				vec.emplace_back(t);
				if(t==v)break;
				t=min(nxt[t],v);
			}
			int c=0;
			// for(int k:vec)
			// {
			// 	if(u<k-1&&k<v)
			// 		c+=f[u][k-1]+f[k-1][v]==f[u][v];
			// 	if(u<k-2&&k<v)
			// 		c+=f[u][k-2]+f[k-2][v]==f[u][v];
			// }
			for(int t=u+1;t<v;t++)
			{
				if(!binary_search(vec.begin(),vec.end(),t)&&f[u][t]+f[t][v]==f[u][v])
					c++;
				if(c>2)break;
			}
			// if(u==1&&v==5)
			// {
			// 	for(int k:vec)
			// 		cerr<<k<<' ';
			// 	cerr<<'\n';
			// 	cerr<<f[1][2]+f[2][4]<<' '<<f[1][4]<<'\n';
			// 	cerr<<c<<'\n';
			// }
			// if(c==1)cerr<<u<<' '<<v<<'\n';
			ans+=c==1;
		}
	}
	// ll ans=0;
	// for(int u=1;u<=n;u++)
	// {
	// 	int t=u;
	// 	int fst=n+1;
	// 	int lst=0;
	// 	int cnt=0;
	// 	while(t!=nxt[t])
	// 	{
	// 		// cerr<<t<<'\n';
	// 		t=nxt[t];
	// 		if(nxt[t]==nxt[t-1])
	// 			cnt++;
	// 		if(cnt==1)
	// 			fst=t+1;
	// 		if(cnt>=2)
	// 		{
	// 			lst=t;
	// 			break;
	// 		}
	// 	}
	// 	cerr<<fst<<' '<<lst<<'\n';
	// 	if(fst<=lst)
	// 		ans+=lst-fst+1;
	// }
	cout<<ans<<'\n';
}
int main()
{
    FIO("migrate");
	int cid,t;
	read(cid,t);
	while(t--)solve();
    return 0;
}