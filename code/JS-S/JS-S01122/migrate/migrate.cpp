#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,d;
int ans;
int taskcase;
int a[2222222];
int tr[11111];
int cnt[2222222];
int sum[2222222];
int qzh[2222222];
int la[2222222];
int l[2222222],r[2222222];
int tol[2222222],tor[2222222];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int y)
{
	while (x<=n)
	{
		tr[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ret=0;
	while (x)
	{
		ret+=tr[x];
		x-=lowbit(x);
	}
	return ret;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>taskcase>>t;
	if (taskcase<=10)
	{
		while (t--)
		{
			cin>>n>>d;
			for (int i=1;i<=n;i++)
			{
				cin>>a[i];
				cnt[i]=la[i]=qzh[i]=sum[i]=0;
			}
			ans=0;
			for (int i=1;i<=n;i++)
			{
				cnt[i]=0;
				sum[i]=1;
				qzh[i]=1;
				qzh[i-1]=0;
				la[0]=i;
				int ll=i;
				for (int j=i+1;j<=n;j++)
				{
					if (a[j]-a[j-1]>d)
					{
						break;
					}
					while (ll<=j&&a[j]-a[ll]>d)
					{
						ll++;
					}
					// cout<<i<<" "<<j<<" "<<ll<<" "<<cnt[ll]<<" "<<la[cnt[ll]]<<endl;
					cnt[j]=cnt[ll]+1;
					sum[j]=qzh[la[cnt[ll]]]-qzh[ll-1];
					if (sum[j]==2)
					{
						ans++;
					}
					la[cnt[j]]=j;
					qzh[j]=qzh[j-1]+sum[j];
					// cout<<cnt[j]<<" "<<sum[j]<<endl;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for (int i=1,j=1;i<=n;i++)
		{
			while (j<=n&&a[j]-a[i]<=d)
			{
				j++;
			}
			tor[i]=j-1;
		}
		for (int i=1,j=1;i<=n;i++)
		{
			while (j<=n&&a[i]-a[j]>d)
			{
				j++;
			}
			tol[i]=j;
		}
		/*for (int i=1;i<=n;i++)
		{
			cout<<i<<" "<<tol[i]<<" "<<tor[i]<<endl;
		}*/
		for (int i=n;i>=1;i--)
		{
			r[i]=r[tor[i]];
			if (tor[tor[i]]<=tor[tor[i]-1])
			{
				r[i]=0;
			}
			else
			{
				r[i]-=max(0ll,tor[tor[i]-1]-tor[i]);
			}
			r[i]+=tor[i]-i;
		}
		for (int i=1;i<=n;i++)
		{
			l[i]=l[tol[i]];
			if (tol[tol[i]]>=tol[tol[i]+1])
			{
				l[i]=0;
			}
			else
			{
				l[i]-=max(0ll,tol[i]-tol[tol[i]+1]);
			}
			l[i]+=i-tol[i];
		}
		/*for (int i=1;i<=n;i++)
		{
			cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
		}*/
		ans=0;
		for (int i=1;i<=n;i++)
		{
			int j=tor[tor[i]-1];
			if (tor[i]-1<=i)
			{
				continue;
			}
			if ((tor[i]-2>i&&j<=tor[tor[i]-2])||j<=tor[i])
			{
				continue;
			}
			int ll=l[i],rr=r[j];
			if (tor[j-1]>=tor[j])
			{
				rr=0;
			}
			else
			{
				rr-=tor[j-1]-j;
			}
			cout<<"aaa"<<tol[i+1]<<endl;
			if (tol[i+1]<=tol[i])
			{
				ll=0;
			}
			else
			{
				ll-=i-tol[i+1];
			}
			/*int pos;
			if (tor[i]-2>i)
			{
				pos=tor[tor[i]-2];
				ans+=(j-pos-1);
			}
			else
			{
				pos=tor[i];
				ans+=(j-pos-1);
			}*/
			// cout<<"::"<<i<<" "<<j<<" "<<pos<<endl;
			ans+=(ll+1)*(rr+1);
			// cout<<i<<" "<<j<<" "<<ll<<" "<<rr<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}