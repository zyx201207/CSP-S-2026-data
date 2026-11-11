#include<cstdio>
template <typename T> void relax(T &a,const T &b){if(a<b) a=b;}
const int maxn=200005;
int a[maxn],s[maxn];
int n,m;
namespace force{
	int b[maxn];
	int ans=0,c=0,len=0;
	void dfs(){
		if(c>m) return; 
		if(len==n){
			int cnt=0,t=1;
			bool first=false;
			for(int i=1;i<=n;i++)if(b[i]){
				if(!first) t=a[i];
				else t&=a[i];
				first=true,cnt++;
			}
			if(cnt==m) relax(ans,t);
			return;
		}
		b[++len]=1,c++;
		dfs();
		c--,b[len--]=0;
		b[++len]=0;
		dfs();
		b[len--]=0;
	}
	void solve(){
		dfs();
		printf("%d\n",ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	force::solve();
	return 0;
}
