#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x=f?-x:x; 
}
template<typename ...Args>
void read(int &x,Args&...args)
{
	read(x);read(args...);
}


//
const int N=5e5+12;
int n,m,a[N],ans,b[N];
bool chk(int l,int r)
{
	return ((r-l+1)*a[r]-(b[r]-b[l-1]))<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n)b[i]=b[i-1]+a[i];
	rep(i,1,n)
	{
		int l=1,r=i,res=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(chk(mid,i))
			{
				r=mid-1;
				res=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}