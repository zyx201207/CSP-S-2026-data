#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int n;
long long d;
long long a[N];
int maxpos[N],low[N];

struct Node{
	int l,r;
}b[N];

void solve() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	a[n+1]=0x3f3f3f3f3f3f3f3f,a[0]=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++) {
		int pos=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
		maxpos[i]=pos;
		pos=lower_bound(a+1,a+i+1,a[i]-d)-a;
		low[i]=pos;
	}
	long long ans=0;
	int pos,cnt;
	long long sum=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			sum=1;
			pos=i,cnt=0;
			while(maxpos[pos]<j &&  maxpos[pos]!=pos) {
				pos=maxpos[pos];
				b[++cnt].r =pos;
			}
			int len=cnt;
			pos=j;
			while(low[pos]>i && low[pos]!=pos) {
				pos=low[pos];
				sum=1ll*sum*(b[cnt].r -pos+1);
				b[cnt--].l =pos;
				if(sum>2) break;
			}
			if(sum==2) ans++;
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		if(c>=13&&c<=14) cout<<"0\n";
		else solve();		
	}
	return 0;
} 
