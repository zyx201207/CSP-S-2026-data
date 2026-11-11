//SN-J00835 把小煜 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
char c[N];
int ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],m+=a[i];
	int lq=1,lu=0,rq=n,ru=0;
	while(lq<rq)
	{
		int lr=a[lq]-lu,rr=a[rq]-ru;
		char aa=c[lq],bb=c[rq];
		if(lr<=rr)
		{
			if(aa!=bb) ans+=lr;
			lq++,lu=0;
			ru+=lr; rr-=lr;
		}
		else
		{
			if(aa!=bb) ans+=rr;
			rq--,ru=0;
			lu+=rr;	lr-=rr;
		}
		if(lr==0) lq++,lu=0;
		if(rr==0) rq--,ru=0;
	}
	cout<<ans;
	return 0;
}
