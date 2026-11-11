#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
const int N=2e6+10;
const ll INF=1e18;

int n;
ll d,a[N];
int cnt[N],f[N];

void solve_A()
{
	ll k=d/(a[2]-a[1]);
	if(k<=1)
	{
		printf("0\n");
		return ;
	}
	
	printf("%lld\n",max(0ll,(ll)n-2*k+1));
}

void solve_force()
{
	ll ans=0;
	for(int u=1;u<=n;u++)
	{
		priority_queue<int,vector<int>,greater<int> > heap;
		int left=u;
		for(int i=0;i<=n;i++) cnt[i]=f[i]=0;
		for(int i=u;i<=n;i++)
		{
			while(a[i]-a[left]>d)
			{
				cnt[f[left]]--;
				left++;
			}
			while(heap.size()&&!cnt[heap.top()]) heap.pop();
			
			if(heap.size()&&cnt[heap.top()]==2) ans++;
			if(heap.size()) f[i]=heap.top()+1;
			if(!cnt[f[i]]) heap.push(f[i]);
			cnt[f[i]]++;
		}
	}
	
	printf("%lld\n",ans);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate4.in","r",stdin);
	
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		
		if(n==1) printf("0\n");
		else if(11<=C&&C<=12) solve_A();
		else solve_force();
	}
	
	return 0;
}