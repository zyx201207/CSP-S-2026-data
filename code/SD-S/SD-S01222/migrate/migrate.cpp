#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,a[N],f[N],s;
int rd()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0' || c>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	c=rd(); t=rd();
	while(t--)
	{
		s=0;
		n=rd(); d=rd();
		for(int i=1;i<=n;i++)
		{
			a[i]=rd();
			f[i]=n+1;
			for(int j=i-1;j>0;j--)
			{
				if(a[i]-a[j]>d)
				{
					break;
				}
				f[j]=i;
				//cout<<"debug "<<j<<" "<<i<<" ";
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=f[i]+1;j<=n;j++)
			{
				if(f[f[i]-1]>=j && f[f[i]-2]<j) s++;
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}//RP++
/*
CCF orz orz orz
I love CCF best,please give me more pts.
*/
