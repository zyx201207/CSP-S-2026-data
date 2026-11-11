#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> c[i];
	int r=n;
	for (int i=1;i<=n;i++){
		long long now=a[i];
		while (c[i+1]==c[i] && i<n) i++,now+=a[i];
		while (now>0 && r>=i){
			if (now-a[r]>=0){
				if (c[i]!=c[r]) ans+=a[r];
				now-=a[r],a[r--]=0;
			}
			else{
				if (c[i]!=c[r]) ans+=now;
				a[r]-=now,now=0;
			}
		}
	}
	cout << ans;
	return 0;
}
