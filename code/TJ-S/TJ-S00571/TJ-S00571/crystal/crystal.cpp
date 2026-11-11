#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<string>
template<typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template<typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

int n;
long long m;

namespace Force{
	const int N = 5e5+10;
	long long a0[N],a[N];
	int op[N];
	int res;
	
	void dfs(int now){
		if(now>m){
			for(int i=1;i<=n;i++) a[i] = a0[i];
			for(int i=1;i<=m;i++) a[op[i]]++;
			std::sort(a+1,a+n+1);
			for(int i=1;i<=n;i++) relax(res,(int)(std::upper_bound(a+1,a+n+1,a[i])-std::lower_bound(a+1,a+n+1,a[i])));
			return;
		}
		for(int x=1;x<=n;x++) op[now] = x,dfs(now+1),op[now] = 0;
	}
	void solve(){
		for(int i=1;i<=n;i++) scanf("%lld",&a0[i]);
		res = 0;
		dfs(1);
		printf("%d\n",res);
	}
}

namespace Better{
	const int N = 5e5+10;
	long long a[N];
	long long s[N];
	
	bool check(int len){
		bool hasres = false;
		long long res = 0;
		for(int l=1,r=len;r<=n;l++,r++){
			if(!hasres) hasres = true,res = a[r]*len-(s[r]-s[l-1]);
			tense(res,a[r]*len-(s[r]-s[l-1]));
		}
		return res<=m;
	}
	void solve(){
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		std::sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];
		int l = 0,r = n,ans = 0;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(mid)) ans = mid,l = mid+1;
			else r = mid-1;
		}
		printf("%d\n",ans);
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	if(n<=5) Force::solve();
	else Better::solve();
	return 0;
}


