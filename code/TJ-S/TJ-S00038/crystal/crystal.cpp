#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5*1e5+10;

int n;
LL m;
LL a[N];
LL s[N];
LL ss[N];
LL ans;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++){
		s[i] = a[i]-a[i-1];
		ss[i] = ss[i-1] + s[i];
	}
	LL l = 1,r = 1,cc = 0;
	while(r <= n){
		while(r < n && (r-l+1)*s[r+1] + cc <= m){
			cc += (r-l+1)*s[r+1];
			r++;
		}
		if(r == n){
			ans = max(ans,r-l+1);
			break;
		}
		if(l == r){
			l++;
			r++;
			continue;
		} 
		ans = max(ans,r-l+1);
		cc -= ss[r]-ss[l];
		l++;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
