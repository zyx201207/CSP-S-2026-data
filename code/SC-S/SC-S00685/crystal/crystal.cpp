#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int pos=1;
	int now=a[1];
	while(m--){
		if(now!=a[pos]){
			now=a[1];
			pos=1;
		}
		a[pos++]+=1;
		for(int i=1;i<=n;i++){
			cerr << a[i] << " ";
		}
		cerr << "\n";
	}
	now=a[1];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==now)ans++;
		else break;
	}
	cout << ans;
	return 0;
}