#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005];
vector<int> vcp[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			vcp[i].clear();
		}
		a[0]=-9e18; a[n+1]=9e18;
		for(int i=1;i<=n;i++)
		{
			int nw=i;
			while(nw<=n)
			{
				if(nw!=i) vcp[i].push_back(nw);
				int l=nw-1,r=n+1;
				while(l+1<r)
				{
					int mid=(l+r)/2;
					if(a[mid]-a[nw]<=d) l=mid;
					else r=mid;
				}
				if(l==nw) break;
				nw=l;
			}
		}
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(!vcp[i].size()) continue;
				if(vcp[i][vcp[i].size()-1]<j) continue;
				int lst=i,num=0;
				for(int k=0;k<vcp[i].size();k++)
				{
					int v=vcp[i][k];
					if(v>=j) continue;
					int nxt=min(vcp[i][k+1],j);
					int l=lst-1,r=nxt+1,mid;
					while(l+1<r)
					{
						mid=(l+r)/2;
						if(a[nxt]-a[mid]<=d) r=mid;
						else l=mid;
					}
					if(v>r) num+=(v-r);
					if(num>1) break;
				}
				if(num==1) cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
