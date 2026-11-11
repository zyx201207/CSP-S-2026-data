#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int qread() {
	int s=0,x=getchar();
	bool p=0;
	while(!isdigit(x)) {
		if(x=='-') {
			p=1;
		}
		x=getchar();
	}
	while(isdigit(x)) {
		s=s*10+x-'0';
		x=getchar();
	}
	return p?-s:s;
}
int n,m,a[200050],res=1,ans=0;
bool vis[200050];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=qread();
	m=qread();
	for(int i=1; i<=n; i++) {
		a[i]=qread();
	}
	for(int i=31; i>=0; i--) {
		int cnt=0;
		res=(1LL<<i);
		for(int j=1; j<=n; j++) {
			if(!vis[a[j]]&&((res&a[j])==res)) {
				cnt++;
			}
		}
		if(cnt<m) {
			continue;
		}
		ans+=res;
		for(int j=1; j<=n; j++) {
			if(!vis[a[j]]&&((res&a[j])!=res)) {
				vis[a[j]]=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 2
2 3 15 12 12

5 3
31 3 1 15 7



*/ 
