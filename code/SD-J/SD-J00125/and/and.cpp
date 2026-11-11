#include<bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}

int w[40],a[N],vis[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read(); 
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=31;j>=0;j--)
		{
			w[j]+=((a[i]&(1<<j))!=0);
		}
		vis[i]=1;
	}
	for(int j=31;j>=0;j--)
	{
		if(w[j]>=m)//第j位多余m个 
		{
			ans+=(1<<j);
			for(int i=1;i<=n;i++)//排除
			{
				if(!vis[i])continue;
				if(!(a[i]&(1<<j)))
				{
					vis[i]=0;
					for(int k=31;k>=0;k--)//去除贡献 
					{
						w[k]-=(bool)(a[i]&(1<<k));
					}
				}
			} 
		}
	}
	write(ans);
	return 0;
}

