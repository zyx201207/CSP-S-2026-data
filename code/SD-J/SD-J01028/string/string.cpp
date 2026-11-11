#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*====================*/
const int N=2e5+10;
int n;
lnt len[N],sum[N];
char c[N]; 
/*====================*/
void solve(void){
	cin >> n;
	string s;
	for (int i=1;i<=n;i++){
		cin >> len[i] >> c[i];
		sum[i]=sum[i-1]+len[i];
		for (int j=1;j<=len[i];j++){
			s+=c[i];
		}
	}
//	cout << s << "\n";
	lnt ans=0;
	int m=s.size();
	for (int i=0;i<(m+1)/2;i++){
		if (s[i]!=s[m-i-1]){
		//	cout << i << " "; 
			ans++;
		}
	}
	cout << ans;
}
/*====================*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
	return 0;
}
//样例3,5过不了，68分 
