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
//#define fin cin
//#define fout cout
const int N=2000010;
int x[N],nxt[N],pre[N],presum[N],sufsum[N],cntnxt[N],cntpre[N];
bool Ed;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cerr<<(&St-&Ed)/1024.0/1024.0<<"\n";
	int c,T;fin>>c>>T;
	while(T--)
	{
		int n,k;fin>>n>>k;
		for(int i=1;i<=n;i++) fin>>x[i];
		for(int i=1;i<=n;i++) presum[i]=sufsum[i]=cntpre[i]=cntnxt[i]=0;
		for(int i=1;i<=n;i++)
		{
			nxt[i]=upper_bound(x+1,x+1+n,x[i]+k)-x-1;
			pre[i]=lower_bound(x+1,x+1+n,x[i]-k)-x;
//			fout<<pre[i]<<" "<<nxt[i]<<"\n";
			cntnxt[nxt[i]]++;
			cntpre[pre[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(nxt[pre[i]]==i) presum[i]=presum[pre[i]]+cntnxt[i];
			else presum[i]=cntnxt[i];
		}
		for(int i=n;i>=1;i--)
		{
			if(pre[nxt[i]]==i) sufsum[i]=sufsum[nxt[i]]+cntpre[i];
			else sufsum[i]=cntpre[i];
		}
//		for(int i=1;i<=n;i++) fout<<cntpre[i]<<" ";
//		fout<<"\n";
		int ans=0;
		for(int i=2;i<n-1;i++)
		{
			if(pre[i+1]==i+1 || pre[i]==i || nxt[i+1]==i+1) continue;
//			if(pre[nxt[i+1]]!=i || nxt[pre[i]]!=i+1) continue;
			int left=0,right=0;
			if(nxt[pre[i]]==i+1) left=presum[pre[i]];
			left+=cntnxt[i+1];
			if(nxt[i]==i+1) left--;
			if(pre[nxt[i+1]]==i) right=sufsum[nxt[i+1]];
			right+=cntpre[i];
			if(pre[i+1]==i) right--;
//			fout<<i<<" "<<left<<" "<<right<<"\n";
			ans+=left*right;
		}
		fout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 3
4 6 7 8 10

0 1
6 2
1 3 5 6 7 8
*/
