#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define double long double
#define endl '\n'
#define pb push_back
#define now_time (1e3*clock()/CLOCKS_PER_SEC)
using namespace std;
const int inf=LLONG_MAX>>1;
int c,T,n,d,a[2000005],p[5005][5005],ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==13||c==14||n<=2){cout<<"0\n";continue;}
		if(c==11||c==12)
		{
			int dd=a[2]-a[1];
			if(dd*2>d)cout<<"0\n";
			else cout<<max(0ll,n-d/dd*2ll+1)<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int k=i,now=a[i],cnt=0;
				while(k!=j)
				{
					while(a[k+1]-now<=d&&k<j)k++;
					if(a[k]==now){cnt=inf;break;}
					now=a[k],cnt++;
				}
				p[i][j]=cnt;
			}
		for(int l=1;l<=n;l++)
			for(int r=l+1;r<=n;r++)
				if(p[l][r]!=inf)
				{
					int f=0,k=l,j;
					while(k!=r)
					{
						j=k;while(a[k+1]-a[j]<=d&&k<r)k++;
						if(j+1<k&&p[k-2][r]==p[k][r]){f=0;break;}
						if(p[k-1][r]==p[k][r]){if(!f)f=1;else{f=0;break;}}
					}
					ans+=f;
				}
		cout<<ans<<endl;
	}
	return 0;
}
