#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
	}
	int l = 1,r = n;
	while(l < r){
		int k = min(a[l],a[r]);
		if(s[l] != s[r]){
			ans += k;
		}
		a[l] -= k;
		a[r] -= k;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	cout << ans;
	return 0;
} 
