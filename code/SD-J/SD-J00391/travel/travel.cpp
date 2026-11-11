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

//const int N=
int mp(char c) {
	if(c=='D'||c=='F') return 1;
	return 0;
}
bool check(char c,char d) {
	if(c>d) swap(c,d);
	if(c=='D'&&d=='F') return 1;
	if(c==d-1) return 1;
	return 0;
}

void Solve() {
	string c1,s1,c2,s2; cin>>c1>>s1>>c2>>s2;
	bool b1=(c1==c2);
	bool b2=(b1&&(s1[0]==s2[0] && s1[1]==s2[1]));
	bool b3=(b2&&(mp(s1[2])==mp(s2[2])));
	bool b4=(b3&(check(s1[2],s2[2])));
	cout<<b1<<b2<<b3<<b4;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);

	Solve();
	return 0;
}

