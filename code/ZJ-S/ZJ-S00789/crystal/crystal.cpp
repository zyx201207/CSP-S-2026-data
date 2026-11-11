#include <bits/stdc++.h>
using namespace std;
typedef long long inte;
// I Love You CCF! Please give me MORE POINTS!!!
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	inte n, m;
	cin>>n>>m; 
	vector<inte> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1, a.end());
	inte ans = 1;
	for(inte i=n;i>0;i--){
		inte cnt=0;
		inte j=i;
		while(cnt<=m && j>0){
			j--;
			cnt+=a[i]-a[j];
		} 
		ans = max(ans, i-j);
	}
	cout<<ans;
	return 0;
} 
