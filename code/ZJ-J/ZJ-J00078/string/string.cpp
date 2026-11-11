#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
ll a[maxn],ans=0ll;
char c[maxn];
int main(){
	freopen("string.in","rb",stdin);
	freopen("string.out","wb",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	while(l<r){
		int cnt=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=cnt;
		}
		a[l]-=cnt;
		a[r]-=cnt;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
//		cerr << '#' <<l<<' '<< r <<' '<<ans <<'\n';
	}
	cout << ans;
	return 0;
}
