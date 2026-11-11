#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N];
int b[N];
int c[N];
int t[N];
void run()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		c[i]=a[i];
		t[a[i]]+=i;
	}
	sort(b+1,b+n+1);
	int f=1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=a[i])
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				t[a[i]]-=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<t[i]<<" ";
		}
		return ;
	}
//	for(int i=1;i<=n-1;i++)
//	{
//		if(cnt[a[i]]==1) continue;
//		for(int j=i;j<=n;j++)
//		{
//			if(a[j]==a[i]&&i!=j)
//			{
//				break;
//			}else{
//				t[a[j]]-=i;
//			}
//		}
//		cnt[a[i]]--;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		f[a[i]].num++;
//		if(cx[f[a[i]].lo]>i)
//		{
//			f[a[i]].lo=i;
//			continue;
//		} 
//		if(f[a[i]]>=2)
//		{
//			for(int j=i-1;j>=f[a[i]].lo;j--)
//			{
//				if(cx[i]>f[a[i]].lo)
//				{
//					continue;
//				}
//				cx[i]=f[a[i]].lo+1;
//				t[i]-=f[a[i]].lo;
//			}
//			f[a[i]].num--;
//			f[a[i]].lo=i;
//		}else{
//			f[a[i]].lo=i;
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j]=c[j];
		}
		for(int j=i;j<=n;j++)
		{
			int last=j;
			for(int k=j-1;k>=i;k--)
			{
				if(a[k]==a[j])
				{
					last=k;
					break;
				}
			}
			if(last==j)
			{
				continue;
			}
			for(int k=j-1;k>=last;k--)
			{
				t[a[k]]--;
				a[k]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	run();
	return 0;
}