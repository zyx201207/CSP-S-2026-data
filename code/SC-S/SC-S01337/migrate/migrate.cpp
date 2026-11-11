#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
int c;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<3)+(x<<1)+ch-'0';
		ch = getchar();
	}
	return x*f;
}

const int N = 2e6+15;
int n,d,arr[N];
int lp[N],rp[N],mxp[N];//rp++
vector<int> vec[N];
int pre[N],suf[N];

void init()
{
	for(int i = 1;i<=n;i++)vec[i].clear(),vec[i].shrink_to_fit();
}
int v[N];
void SOL()
{
	for(int i = 1;i<=n;i++)
	{
		v[i] = 1;		
		for(int j = i;j>=1;j--)
		{
			for(int k = j-1;k>=lp[j];k--)
			{
				v[k]+=v[j];
			}
		}
		for(int j = 1;j<=n;j++)
		{
			if(v[j] == 1)pre[i]++;
			v[j] = 0;
		}
		v[i] = 1;
		for(int j = i;j<=n;j++)
		{
			for(int k = j+1;k<=rp[j];k++)
			{
				v[k]+=v[j];
			}
		}
		for(int j = 1;j<=n;j++)
		{
			if(v[j] == 1)suf[i]++;
			v[j] = 0;
		}
	}
	
	int ans = 0;
	for(int i = n;i>=1;i--)
	{
		int tov = lp[i];
		for(auto u:vec[tov+1])
		{
			ans += pre[u]*suf[i];
//			cout<<u<<' '<<i<<' '<<pre[u]*suf[i]<<endl;
		}
	}
	cout<<ans<<'\n';
}
void solve()
{
	n = read(),d = read();
	int ans = 0;
	for(int i = 1;i<=n;i++)arr[i] = read(),pre[i] = suf[i] = 0;
	int ptr = 1;
	for(int i = 1;i<=n;i++)
	{
		while(arr[ptr+1]-arr[i] <= d && ptr<n)
		{
			++ptr;
		}
		rp[i] = ptr;
//		cout<<"?? "<<i<<' '<<rp[i]<<endl;
		mxp[i] = max(mxp[i-1],rp[i]);
		if(rp[i] > i+1)
			vec[rp[i]].push_back(i);
	}
	ptr = n;
	for(int i = n;i>=1;i--)
	{
		while(arr[i]-arr[ptr-1] <= d && ptr > 1)
		{
			--ptr;
		}
		lp[i] = ptr;
	}
	
	if(!c && c <= 10 && n <= 300)return SOL(),void();
	
	int lst = n;
	arr[n+1] = 2e18;
	for(int i = n;i>=1;i--)
	{
		if(arr[i+1] - arr[i] > d)lst = i;
		int tov = lp[i];
		ans += vec[tov+1].size()*(lst-i+1);
		lst = i-1; 
	}
	cout<<ans<<'\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifndef DEBUG
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#else
	freopen("migrate4.in","r",stdin);
	freopen("myans.out","w",stdout);
#endif
	int T;
	c = read(),T = read();
	------c;
	while(T--)
	{
		init();
		solve();
	}

	return 0;
}
/*
15:25 观察到要形成2种方案必须满足u->u+1->u+3/u->u+2->u+3.d_u_u+2 <= d && d_u+1_u+3 <= d && d_u_u+3 > d称此时u合法
	  但是要形成2种方案还需保证………………
15:55 猜想：对于u->u+1,答案为1~u-1中向右能到达的最远点为u+1的数量与u+1~n中向左能到达的最远点为u的数量之积，try 
*/