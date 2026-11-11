#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n,m,a[maxn],ans,s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) s[i] = a[i] - a[i-1];
	for(int i = 1;i <= n;i++){
		int now = 1,cost = m,last = 0;
		for(int j = i-1;j >= 1;j--){
			last += s[j];
			if(last <= cost){
				now++;
				cost -= (a[i] - a[j]);
			} 
			else break;
		}
		ans = max(ans,now);
	}
	cout << ans;
	return 0;
} 
