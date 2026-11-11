#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template <typename ty>
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T>
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
const int N=5e5+50;
ll a[N];
ll sum[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n; ll m;
	read(n,m);
	for(int i=1;i<=n;i++) read(a[i]); 
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	int p=1; int res=0;
	for(int i=1;i<=n;i++) {
		while(a[i]*(i-p+1)-(sum[i]-sum[p-1])>m) p++;
		res=max(res,i-p+1);
	}
	printf("%d",res);
	return 0;
}

