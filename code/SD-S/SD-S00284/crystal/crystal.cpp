#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
#define rint FastRead()
#define wint FastWrite

int FastRead() {
	int ans=0,sgn=0,ch=getchar();
	while(ch==' '||ch=='+'||ch=='\r'||ch=='\n') ch=getchar();
	if(ch=='-') ch=getchar(),sgn=1;
	while(ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+(ch^48),ch=getchar();
	return sgn?-ans:ans;
}
void FastWrite(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) wint(x/10);
	putchar(x%10+'0');
}

const int N=5e5+10;

ll a[N],pre[N];

void Solve() {
	int n,res=0; ll m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int ans=-1,l=1,r=i;
		while(l<=r) {
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) {
				r=mid-1;
				ans=mid;
			} else l=mid+1;
		}
		if(ans!=-1) res=max(res,i-ans+1);
	}
	cout<<res;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	Solve();
	return 0;
}

