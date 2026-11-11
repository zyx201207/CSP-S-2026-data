#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 2e6 + 10;
int n,d,A[N],nxt[N],C[N][2],g[N],dist[N];list<int> st;
int lowbit(int x) {return x & (-x);}
void mdf(int op,int ix,int w) 
{
	for(int i=ix;i<=n;i+=lowbit(i)) 
		C[i][op] += w;
}
int sum(int op,int x) {int kkk = 0;for(int i=x;i;i-=lowbit(i)) kkk+=C[i][op];return kkk;}
void add(int x,int y,int op,int w)
{
	if(x > y) return ;
	mdf(op,x,w);mdf(op,y+1,-w);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) C[i][0] = C[i][1] = 0;
		for(int i=1;i<=n;i++) cin>>A[i];
		st.clear();st.push_back(n);
		for(int i=n-1;i>=1;i--)
		{
			while(st.size() && A[st.front()] > A[i] + d) st.pop_front();
			st.push_back(i);
			nxt[i] = st.front();
		}
		if(c <= 6)
		{
			int ans = 0;
			for(int i=1;i<=n;i++)
			{
				for(int k=i;k<=n;k++) dist[k] = INF;
				dist[i] = 1;g[i] = 1;
				for(int k=i;k<=n;k++)
				{
					for(int l=nxt[k];l>=k+1;l--) 
					{
						if(dist[l] > dist[k] + 1) dist[l] = dist[k]+1,g[l] = g[k];
						else if(dist[l] == dist[k] + 1) g[l] += g[k];
						else break;
					}
				}
				for(int j=i;j<=n;j++) if(g[j] == 2) ans++;
			}
			cout<<ans<<"\n";
			continue;
		}
//		add(4,4,1,1);
//		cout<<sum(1,1)<<"\n";
//		cout<<"nxt:";for(int i=1;i<=n;i.++) cout<<nxt[i]<<" ";cout<<"\n";
		mdf(0,1,1);
		for(int i=1;i<=n;i++)
		{
			if(nxt[i] == i) continue;
			int w0=sum(0,i),w1=sum(1,i); 
			if(nxt[i] == i + 1 && nxt[i-1] <= i)
			{
				add(nxt[i-1]+1,nxt[i],0,w0);
				add(i+1,nxt[i],1,w1);
			}
			
			add(max(nxt[i]+1,nxt[nxt[i]-2]+1),nxt[nxt[i]-1],1,w0);
//			cout<<i<<",0:";for(int j=1;j<=n;j++) cout<<sum(0,j)<<" ";cout<<"\n";
//			cout<<i<<",1:";for(int j=1;j<=n;j++) cout<<sum(1,j)<<" ";cout<<"\n\n";
		}
		int ans = 0;
		for(int i=1;i<=n;i++) ans += sum(1,i);
		cout<<ans<<"\n";
	}
	return 0;
}