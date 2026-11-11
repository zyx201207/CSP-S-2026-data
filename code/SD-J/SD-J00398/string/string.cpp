#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n;
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int tot = 1;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=tot;j<=tot+x;j++){
			s[j] = c;
		}
		tot = tot+x;
	}
	int ans = 0;
	tot--;
	int mid = 0;
	if(tot%2 == 0)mid = tot/2;
	else mid = (tot+1)/2-1;
	for(int i=1;i<=mid;i++){
		if(s[i] != s[tot-i+1])ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
