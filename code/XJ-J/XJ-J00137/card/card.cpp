//card
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int next[N];
int t[N];//zan cun wei zhi
int tt[N];
int ans[N];
void ch() {
	for(int s=1; s<=n; s++) {
		for(int i=s; i<=n;) {
			tt[a[i]]=1;
			if(next[i]==0) i+=1;
			else i=next[i]+1;
		}
		for(int i=1; i<=m; i++) {
			ans[i]+=tt[i];
			tt[i]=0;
		}
	}

}
signed main() {
	/**/
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=n; i>=1; i--) {
		next[i]=t[a[i]];
		t[a[i]]=i;//dang qian wei zhi
	}
/*
	cout << "##############################\n";
	for(int i=1; i<=n; i++) {
		cout << next[i] << ' ';
	}
	cout << "\n##############################\n";
*/
	//int flag=0
	ch();
	for(int i=1; i<=m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
