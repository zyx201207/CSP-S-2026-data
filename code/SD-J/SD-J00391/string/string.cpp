#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
#define rint FastRead()
#define wint FastWrite

int FastRead() {
	int ans=0,sgn=0,ch=getchar();
	while(ch==' '||ch=='+'||ch=='\n'||ch=='\r') ch=getchar();
	if(ch=='-') sgn=1,ch=getchar();
	while(ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+(ch^48),ch=getchar();
	return sgn?-ans:ans;
}
void FastWrite(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) wint(x/10);
	putchar(x%10+'0');
}

const int N=2e5+10;

ll s[N],t[N];
char c[N];

void Solve() {
	int n; cin>>n;
	for(int i=1;i<=n;i++) {
		int x; cin>>x>>c[i];
		s[i]=t[i-1]+1,t[i]=s[i]+x-1;
	}
	ll l=1,r=n,lpos=1,rpos=t[n],ans=0;
	while(l<r) {
		int el=min(t[l]-lpos+1,rpos-s[r]+1);
		if(c[l]!=c[r]) ans+=el;
		lpos+=el,rpos-=el;
		if(lpos>t[l]) l++;
		if(rpos<s[r]) r--;
	}
	cout<<ans;
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);

	Solve();
	return 0;
}

