#include<bits/stdc++.h>
using namespace std;
const int Nax = 1e6+5;
int C,T;
int N;
long long D;
long long X[Nax+5];
long long F[Nax+5];
int cnt[Nax+5];
int t[5];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&N,&D);
		for(int i = 1;i <= N;i++) scanf("%lld",X+i);
		long long ans = 0;
		stack<int> sta;
		for(int i = 1;i <= N;i++)
		{
			if((C == 11 || C == 12) && i > 1)
			{
				while(sta.size() && i+sta.top() > N) sta.pop();
					ans += sta.size();
				// cout << sta.size() << endl;
				continue;
			}
			memset(F,0x3f,sizeof(F));
			memset(cnt,0,sizeof(cnt));
			F[i] = 0,cnt[i] = 1;
			deque<int> q;
			q.push_back(i);
			for(int j = i+1;j <= N;j++)
			{
				while(q.size() && X[j]-X[q.front()] > D) q.pop_front();
				int k;
				t[1] = t[2] = t[3] = 0;
				for(k = 1;k <= 3 && q.size();k++)
				{
					int l = q.front();
					t[k] = l;
					q.pop_front();
					// cout << l << ' ' << F[l] << ' ' << cnt[l] << endl;
					if(F[l]+1 > F[j]) break;
					else if(F[l]+1 < F[j])
					{
						F[j] = F[l]+1;
						cnt[j] = cnt[l];
					}
					else if(F[l]+1 == F[j])
						cnt[j] = min(cnt[j]+cnt[l],3);
				}
				// cout << F[j] << ' ' << cnt[j] << endl;
				for(;k >= 1;k--) if(t[k]) q.push_front(t[k]);
				while(q.size() && F[q.back()] > F[j]) q.pop_back();
				q.push_back(j);
			}
			if((C == 11 || C == 12) && i == 1)
			{
				for(int j = i+1;j <= N;j++)
					if(cnt[j] == 2)
						ans++,sta.push(j-i);
				// cout << sta.size() << endl;
			}
			else
			{
				// cout << ans << endl;
				for(int j = i+1;j <= N;j++)
					if(cnt[j] == 2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}