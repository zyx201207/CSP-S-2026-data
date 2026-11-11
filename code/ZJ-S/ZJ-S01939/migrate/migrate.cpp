#include<bits/stdc++.h>
using namespace std;
const int N(5005);
int C,T,n,dis[N],f[N],q_f[N];
long long d,c[N],q_c[N];
void subtask1to10()
{
	for(cin >> T;T;--T)
	{
		long long ans(0);
		cin >> n >> d;
		long long pre,tmp;
		cin >> pre;
		for(int i(2);i <= n;++i)
		{
			cin >> tmp;
			c[i] = tmp-pre;
			q_c[i] = c[i]+q_c[i-1];
			pre = tmp;
		}
		for(int i(1);i <= n;++i)
		{
			memset(dis,0,sizeof dis);
			memset(f,0,sizeof f);
			memset(q_f,0,sizeof q_f);
			f[i] = 1;
			q_f[i] = 1;
			for(int j(i+1);j <= n and c[j] <= d;++j)
			{
				int l(i),r(j-1);
				while(l < r)
				{
					int mid(l+r>>1);
					if(q_c[j]-q_c[mid] <= d) r = mid;
					else l = mid+1;
				}
				dis[j] = dis[l]+1;
				int L(l),R(j);
				while(L < R)
				{
					int mid(L+R>>1);
					if(dis[mid] < dis[j]) L = mid+1;
					else R = mid;
				}
				f[j] = q_f[L-1]-q_f[l-1];
				q_f[j] = f[j]+q_f[j-1];
				if(f[j] == 2) ++ans;
			}
		}
		cout << ans << "\n";
	}
}
void subtaskA()
{
	for(cin >> T;T;--T)
	{
		long long ans(0);
		cin >> n >> d;
		long long D,tmp;
		cin >> D;
		if(n == 1)
		{
			cout << "0\n";
			continue;
		}
		cin >> tmp;
		D = tmp-D;
		for(int i(3);i <= n;++i) cin >> tmp;
		long long s(d/D);
		if(s <= 1)
		{
			cout << "0\n";
			continue;
		}
		for(int i(1);i+2*s-1 <= 1ll*n;++i)
		{
			++ans;
		}
		cout << ans << "\n";
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> C;
	if(C <= 10)
	{
		subtask1to10();
		return 0;
	}
	subtaskA();
	return 0; 
}
