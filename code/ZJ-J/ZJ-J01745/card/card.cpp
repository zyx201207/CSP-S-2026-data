#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],t[500005];
int c[300005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		c[a[i]]++;
		if(c[a[i]]>=2){
			int la=1;
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					la=j;
				}
			}
			for(int j=la+1;j<=i;j++){
				t[j]=max(t[j],la);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=(i-t[i]);
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}