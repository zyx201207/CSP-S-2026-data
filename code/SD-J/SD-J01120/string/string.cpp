#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,a,l,ans;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		l+=a; 
	}
	for(int i=1,j=l;i<=j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout << ans;
	return 0;
}

