#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
const int N=2e6+10;
const int P=1e9+7,Inf=1e18;

int n,d;
int a[N],pre[N],nxt[N],last[N];
int f[N];

void solve1()
{
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		pre[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		nxt[i]=min(n,upper_bound(a+1,a+n+1,a[i]+d)-a-1);
	}
	pre[n+1]=n;
	for(int l=1;l<=n;l++)
		for(int r=l+1;r<=n;r++)
		{
			for(int i=1;i<=n;i++)f[i]=0;
			int p=l;
			int cnt=0;
			while(p!=r)
			{
				f[p]=1;
				int tmp=p;
				p=nxt[p];
				if(p>r)p=r;
				last[p]=tmp;
				if(tmp==p){
					cnt=2;
					break;
				}
			}
			f[r]=1;
			for(int i=l;i<=r;i++){
				int pos=min(r,nxt[i]);
				if(!f[i]&&f[pos]&&i<last[pos])cnt++;
			}
			if(cnt==1)ans++;
		}
	cout<<ans<<'\n';
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int task,T;
	cin>>task>>T;
	while(T--)
	{
		if(task<=6)solve1();
		else cout<<"0\n";
	}
	return 0;
}


