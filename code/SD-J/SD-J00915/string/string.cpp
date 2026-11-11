#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char c[200010];
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
