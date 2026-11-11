#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
struct node {
	int l,r;
} dl[N],dr[N];
int n,d,x[N];
node check(int le,int ri) {
	int l,r;
	node q={N,-1};
	l=1,r=n;
	while(l<r) {
		int mid=l+(r-l)/2;
		if(x[mid]>=le)
			r=mid;
		else l=mid+1;
	}
	if(x[r]>=le) q.l=r;
	l=1,r=n;
	while(l<r) {
		int mid=l+(r-l+1)/2;
		if(x[mid]<=ri)
			l=mid;
		else r=mid-1;
	}
	if(x[l]<=ri) q.r=l;
	return q;
}
int dis(node q) {
	if(q.l>q.r) return 0;
	return q.r-q.l+1;
}
void solve() {
	int ans=0;
	cin>>n>>d;
	for(int i=1; i<=n; i++)
		cin>>x[i];
	if(n<4) {
		cout<<"0\n";
		return;
	}
	for(int i=1; i<=n; i++) {
		int ll=x[i]-d,lr=min(x[i]-1,x[i+1]-d-1),rl=max(x[i]+1,x[i-1]+d+1),rr=x[i]+d;
		dl[i]=check(ll,lr),dr[i]=check(rl,rr);
	}
	for(int i=1; i<=n; i++) {
		if(x[i+1]-x[i]>=d) continue;
		int ll=x[i+1]-d,lr=min(x[i]-1,x[i+2]-d-1),rl=max(x[i+1]+1,x[i-1]+d+1),rr=x[i]+d;
		node ql=check(ll,lr),qr=check(rl,rr);
		int numl=0,numr=0;
		while(dis(ql)) {
			numl+=dis(ql);
			ql=dl[ql.l];
			cout<<ql.l<<"\n";
		}
		cout<<"\n";
		while(dis(qr)) {
			numr+=dis(qr);
			qr=dr[qr.r];
			cout<<qr.l<<"\n";
		}
		ans+=numl*numr;
	}
	cout<<ans<<"\n";
}
signed main() {
	//freopen
	freopen("migrate.in","r",stdin);
	freopen("migeate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
		solve();
	return 0;
}

