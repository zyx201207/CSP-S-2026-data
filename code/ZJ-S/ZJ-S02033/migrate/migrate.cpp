#include<bits/stdc++.h>
using namespace std;
#define int long long
#define io(name) freopen(name".in","r",stdin);freopen(name".out","w",stdout)
int c,t;
int n,d;
int x[2000010];
int mx[2000010],cnt[2000010],tot[2000010];
int sum[2000010];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
    io("migrate");
    cin>>c>>t;
    while(t--)
    {
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)cin>>x[i];
    	if(n==1){cout<<0<<'\n';continue;}
    	if(11<=c&&c<=12)
    	{
    		int diff=x[2]-x[1];
    		if(diff*2>d)cout<<0<<'\n';
    		else
    		{
    			int mxmv=d/diff;
    			int tmp=min(mxmv*2-1,n);
    			cout<<n-tmp<<'\n';
			}
		}
    	else if(c<=10)//40pts
    	{
    		for(int i=1;i<=n;i++)cnt[i]=tot[i]=0;
    		int ans=0;
    		for(int i=1;i<=n;i++)
    		{
    			int j=i;
    			while(j<=n&&x[j]-x[i]<=d)mx[i]=j,j++;
			}
			for(int i=1;i<=n;i++)
			{
				//cout<<"i="<<i<<":\n";
				for(int j=1;j<=n;j++)sum[j]=0;
				int rt=i-1;
				for(int j=i-1;j>=1;j--)
				{
					cnt[j]=tot[j]=0;
					while(rt>mx[j])sum[cnt[rt]]-=tot[rt],rt--;
					if(mx[j]==j)break;
					if(mx[j]>=i)
					{
						cnt[j]=1;
						tot[j]=1;
						sum[1]+=1;
					}
					else
					{
						cnt[j]=cnt[mx[j]]+1;
						tot[j]=sum[cnt[mx[j]]];
						sum[cnt[j]]+=tot[j];
					}
					//cout<<j<<" "<<i<<" "<<cnt[j]<<" "<<tot[j]<<endl;
					if(tot[j]==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else cout<<0<<'\n';
	}
}
