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
int a[N],bit[N][31];
bool flag[N];

void Solve() {
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i]; int t=a[i],j=0;
		while(t) {
			bit[i][j]=(t&1);
			t>>=1;
			j++;
		}
	}
	int step=0;
	vector<int> ch;
	for(int j=30;j>=0;j--) {
		if(step==0) {
			ch.clear(); int cnt=0;
			for(int i=1;i<=n;i++) {
				if(bit[i][j]) {
					ch.push_back(i);
					cnt++;
				}
			}
			if(cnt>=m) {
				step++;
				for(auto i:ch) {
					flag[i]=1;
				}
			}
		} else if(step==1) {
			vector<int> tmp; int cnt=0;
			for(int i=1;i<=n;i++) {
				if(flag[i] && bit[i][j]) {
					cnt++;
				} else if(flag[i] && !bit[i][j]) {
					tmp.push_back(i);
				}
			}
			if(cnt>=m) {
				for(auto i:tmp) {
					flag[i]=0;
				}
			}
		}
	}
	if(step==0) {
		cout<<0;
		return ;
	}
	int cur=0,ans=(1ll<<31)-1;
	for(int i=1;i<=n;i++) {
		if(flag[i] && cur<=m) {
			ans=(ans&a[i]);
			cur++;
		}
	}
	cout<<ans;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);

	Solve();
	return 0;
}

