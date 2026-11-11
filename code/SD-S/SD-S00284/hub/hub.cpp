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

//const int N=

void Solve() {
	int c,t; cin>>c>>t;
	while(t--) cout<<"0\n";
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	Solve();
	return 0;
}

