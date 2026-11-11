#include<bits/stdc++.h>
using namespace std;
#define il inline
#define int long long
#define ll long long
bool St;
struct IO
{
	static const int Size=(1<<21);
	char buf[Size],*p1,*p2;
	int st[105],Top;
	~IO(){clear();}
	il void clear(){fwrite(buf,1,Top,stdout);Top=0;}
	il char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,Size,stdin),p1==p2)?EOF:*p1++;}
	il void pc(const char c){Top==Size&&(clear(),0);buf[Top++]=c;}
	il IO& operator >>(char& c){while(c=gc(),c==' ' || c=='\n' || c=='\r');return *this;}
	template<typename T>il IO& operator >>(T& x)
	{
		x=0;bool f=0;char c=gc();
		while(!isdigit(c)){if(c=='-') f=1;c=gc();}
		while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=gc();}
		f?x=-x:0;
		return *this;
	}
	il IO& operator >>(string& s)
	{
		s="";char c=gc();
		while(c==' ' || c=='\n' || c=='\r') c=gc();
		while(c!=' ' && c!='\n' && c!='\r' && c!=EOF) s+=c,c=gc();
		return *this;
	}
	il IO& operator <<(const char c){pc(c);return *this;}
	template<typename T>il IO& operator <<(T x)
	{
		if(x<0) pc('-'),x=-x;
		do st[++st[0]]=x%10,x/=10; while(x);
		while(st[0]) pc(st[st[0]--]+'0');
		return *this;
	}
	il IO& operator <<(const string s){for(auto c:s) pc(c);return *this;}
	il IO& operator <<(const char* c){for(int i=0;c[i];i++) pc(c[i]);return *this;}
} fin,fout;
const int N=500010;
int a[N],pre[N];
bool Ed;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cerr<<(&St-&Ed)/1024.0/1024.0<<"\n";
	int n,m;fin>>n>>m;
	for(int i=1;i<=n;i++) fin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ret=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m) r=mid-1,ret=mid;
			else l=mid+1;
		}
//		fout<<ret<<" "<<i<<"\n";
		ans=max(ans,i-ret+1);
	}
	fout<<ans;
	return 0;
}
