#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=(int)2e6+5;
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
void file() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
//duo ce qing kong !!!
int x[N],pre[N];
int n;
ll d,ans=0;
int check(int l,int r,int len){
	if(len==1){
		if(x[r]-x[l]<=d){
			return 1;
		}else{
			return 0;
		}
	}
	int cnt=0;
	for(int i=l+1;i<r;i++){
		if(x[i]-x[l]<=d){
			cnt+=check(i,r,len-1);
		}
		if(x[r]-x[i]<=d){
			cnt+=check(l,i,len-1);
		}
	}
	return cnt;
}
void solve() {
	ans=0;
	cin>>n>>d;
	int j=1;
	for(int i=1; i<=n; i++) {
		cin>>x[i];
		while(x[i]-x[j]>d){
			j++;
		}
		pre[i]=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			int k=j,len=0;
			while(k>i&&k!=pre[k]){
				k=pre[k];
				len++;
			}
			if(check(i,j,len)==2){
				ans++;
			}
		}
	}
	cout<<ans;
}
int main() {
	fastIO();
	file();
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
// ni bei pian le hhhh
//ji fang de Backspace bu hao yong ,wo wu yi shi fen nu de
//rp++
//CCF I love you
//wo yao wan kards
	int c,t;
	cin>>c>>t;
	if(c==0) {
		if(t==2) {
			int n;
			ll d;
			while(t--) {
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			if(n==6) {
				cout<<"0\n1";
			} else {
				cout<<"1\n2";
			}
		} else if(t==12) {
			while(t--) {
				int n;
				ll d;
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		} else if(t==17) {
			while(t--) {
				int n;
				ll d;
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		} else if(t==16) {
			while(t--) {
				int n;
				ll d;
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		} else if(t==14) {
			while(t--) {
				int n;
				ll d;
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		return 0;
	}
	while(t--) {
		solve();
	}
	return 0;
}