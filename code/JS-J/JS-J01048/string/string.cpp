#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,a,c,ft=1,bk;
long long ans;
struct node{
	int l;
	char s;
}b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bk=n;
	for (long long i=1;i<=n;i++)
	{
		cin>>b[i].l>>b[i].s;
	}
	while(ft<bk)
	{
		if (b[ft].s!=b[bk].s) ans+=min(b[ft].l,b[bk].l);
		if (b[ft].l>b[bk].l)
		{
			long long k=b[ft].l-b[bk].l;
			
			while(k>=b[bk-1].l)
			{
				if (b[ft].s==b[bk].s) bk--;
				else
				{
					ans+=k-b[bk].l;
					k-=b[bk].l;
					bk--;
				}
			}
			while (b[ft].s==b[bk].s) bk--;
			if (ft>=bk) break;
			//bk++;
			ans+=k;
			//cout<<k<<endl;
			b[bk].l-=k;
		}
		else
		{
			long long k=b[bk].l-b[ft].l;
			while(k>=b[ft+1].l)
			{
				if (b[ft].s==b[bk].s) ft++;
				else
				{
					ans+=k-b[ft].l;
					k-=b[ft].l;
					ft++;
				}
			}
			while (b[ft].s==b[bk].s) ft++;
			if (ft>=bk) break;
			//ft--;
			ans+=k;
			b[ft].l-=k;
		}
		ft++;
		bk--;
	}
	//if (ans<0) ans=0;
	cout<<ans;
	return 0;
}
