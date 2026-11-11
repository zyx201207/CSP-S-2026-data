#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n;
long long a[MAXN],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;++i)cin >> a[i];
	sort(a+1,a+1+n);
	int r=n,l=n,ans=1,cnt=1;
	long long used=0;
	while(l-1>=1 && a[r]-a[l-1]+used<=m){
		used+=(a[r]-a[l-1]);
		l--;
		cnt++;
	}
	ans=max(cnt,ans);
	for(r--;r>=1;--r){
		used-=(a[r+1]-a[r])*(cnt-1);
		cnt--;
		while(l-1>=1 && a[r]-a[l-1]+used<=m){
			used+=(a[r]-a[l-1]);
			l--;
			cnt++;
		}
		ans=max(cnt,ans);
	}
	cout << ans;
	
	return 0;
} 
