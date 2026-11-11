#include <bits/stdc++.h>
using namespace std;
#define drintf(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
ll rd(){
	ll x=0ll;
	bool flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return flag?x:-x;
}
const int maxn=5e5+10;
int n;
ll m;
ll a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();
	m=rd();
	for(int i=1;i<=n;++i){
		a[i]=rd();
	}
	sort(a+1,a+n+1);
	ll ls=0ll;
	int ans=0;
	for(int i=1,j=1;i<=n;++i){
		ls+=(i-j)*(a[i]-a[i-1]);
		while(ls>m){
			ls-=a[i]-a[j];
			++j;
		} 
		ans=max(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}


