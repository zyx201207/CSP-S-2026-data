#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m,a[maxn];
int main(){
	freopen("and.in","rb",stdin);
	freopen("and.out","wb",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1<<29;i;i/=2){
		int cnt=0;
		vector<int> now;
		for(int j=1;j<=n;j++){
			if(a[j]&i){
				cnt++;
				now.push_back(a[j]);
			}
		}
		if(cnt<m) continue;
		sort(now.begin(),now.end(),greater<int>());
		int ans=now[0];
		for(int i=1;i<m;i++){
			ans&=now[i];
		}
		cout << ans;
		return 0;
	}
}
