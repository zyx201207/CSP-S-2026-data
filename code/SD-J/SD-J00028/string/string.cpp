#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int c[200010];
char v[200010];
void solve(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> c[i] >> v[i];
	}
	int lef=1,rit=n,cnt=0;
	while (lef<rit){
		if (v[lef]!=v[rit]){
			if (c[lef]>c[rit]) cnt+=c[rit],c[lef]-=c[rit],c[rit--]=0;
			else if (c[lef]==c[rit]) cnt+=c[lef],c[lef]=c[rit]=0,rit--,lef++;
			else cnt+=c[lef],c[rit]-=c[lef],c[lef++]=0;
		}else{
			if (c[lef]>c[rit]) c[lef]-=c[rit],c[rit--]=0;
			else if (c[lef]==c[rit]) c[lef]=c[rit]=0,rit--,lef++;
			else c[rit]-=c[lef],c[lef++]=0;
		}
	}
	cout << cnt << endl;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}

