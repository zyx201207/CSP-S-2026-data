#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,cnt=0,b[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	b[i]=b[i-1]+a[i];
	}
	if(n==1){
		cout << 1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		int t=a[i]*(i-1)-b[i-1];
		if(t<=m){
			cnt=i;
			if(cnt>ans){
				ans=cnt;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
