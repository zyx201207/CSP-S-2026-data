#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,ans,rt[2000010],a[2000010],nxt[2000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			nxt[i]=0;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int l=2;
		for(int i=1;i<=n;i++)
		{
			l=min(l,i);
			while(l<n&&a[l+1]-a[i]<=d)
			{
				l++;
			}
			if(l==i)
			{
				nxt[i]=0;
			}
			else
			{
				nxt[i]=l;
			}
		}
		rt[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i+1]-a[i]<=d)
			{
				rt[i]=rt[i+1];
			}
			else
			{
				rt[i]=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int l1,l2,l3;
			l1=nxt[i];
			l2=l1-1;
			if(l2==i)
			{
				l2--;
			}
			if(l1==0||l2==0)
			{
				continue;
			}
			l3=l2-1;
			if(l3==i)
			{
				l3--;
			}
			int oo=l1+1;
			if(!l3||a[i]-a[l3]>d)
			{
				while(l1&&l2)
				{
//					cout<<i<<" "<<l1<<" "<<l2<<" "<<oo<<"\n";
					oo=min(max(oo,l1+1),n);
					while(oo<n&&a[oo]-a[l2]<=d&&a[oo]-a[l1]<=d)
					{
//						cout<<oo<<" "<<n<<"\n";
						oo++;
						ans++;
					}
					if(oo>l1&&a[oo]-a[l2]<=d&&a[oo]-a[l1]<=d)
					{
//						cout<<oo<<" "<<l1<<" "<<l2<<"\n";
						ans++;
					}
					l1=nxt[l1];
					l2=nxt[l2];
				}
			}
			else
			{
				while(l1&&l2&&l3)
				{
//					cout<<i<<" "<<l1<<" "<<l2<<" "<<l3<<" "<<oo<<"\n";
					oo=max(oo,l1+1);
					while(oo<n&&a[oo]-a[l3]<=d)
					{
						oo++;
					}
					while(oo<n&&a[oo]-a[l2]<=d&&a[oo]-a[l1]<=d)
					{
						oo++;
						if(a[oo]-a[l3]>d)
						{
							ans++;
						}
					}
					if(a[oo]-a[l3]>d&&a[oo]-a[l2]<=d&&a[oo]-a[l1]<=d)
					{
						ans++;
					}
					l1=nxt[l1];
					l2=nxt[l2];
					l3=nxt[l3];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
4 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 1000000000000000000



0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
-2 -1 0 1 2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
