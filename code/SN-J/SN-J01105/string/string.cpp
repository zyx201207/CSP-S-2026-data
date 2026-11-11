#include<bits/stdc++.h>
#define lint long long
using namespace std;
lint n,sum,ans,a[200002];
char c[200002];
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i],sum += a[i];
	int l = 1,r = n;
	while(l <= r){
		if(a[l] == a[r]){
			if(c[l] != c[r]) ans += a[l];
			l++,r--;
		}else if(a[l] < a[r]){
			if(c[l] != c[r]) ans += a[l];
			a[r] -= a[l],l++; 
		}else{
			if(c[l] != c[r]) ans += a[r];
			a[l] -= a[r],r--;
		}
		if(l == r) break;
	}
	cout << ans;
	return 0;
} 
