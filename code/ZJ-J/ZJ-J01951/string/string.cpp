#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct node{
	int x;
	char y;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1 ; i<=n ; i++){
		cin >> a[i].x >> a[i].y;
	}
	int l=1,r=n;
	while (l<r){
		if (a[l].x==a[r].x){
			if (a[l].y!=a[r].y) ans+=a[l].x;
			l++;
			r--;
		}
		else if (a[l].x>a[r].x){
			if (a[l].y!=a[r].y) ans+=a[r].x;
			a[l].x-=a[r].x;
			r--;
		}
		else if (a[l].x<a[r].x){
			if (a[l].y!=a[r].y) ans+=a[l].x;
			a[r].x-=a[l].x;
			l++;
		}
	}
	cout << ans;
	return 0;
}
