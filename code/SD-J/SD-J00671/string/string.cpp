#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ans,l,cnt;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a >> c;
		for (int j=1;j<=a;j++) s[++cnt]=c;
	}
	for (int i=1;i<=cnt;i++){
		if (s[i]!=s[cnt+1-i]){
			ans++;
			s[cnt+1-i]=s[i];
		}
	}
	cout << ans;
	return 0;
}
