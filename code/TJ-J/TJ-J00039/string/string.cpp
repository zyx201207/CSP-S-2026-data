#include<bits/stdc++.h>
using namespace std;
struct node{
	long long cnt;
	string y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].cnt;
		cin >> a[i].y;
	}
	long long ans = 0, sum = n, p;
	for(int l = 1,r = n;l<=r;){
		p = min(a[l].cnt,a[r].cnt);
		//cout << p << " ";
		if(a[l].y!=a[r].y) ans+=p;
		a[l].cnt-=p;
		a[r].cnt-=p;
		if(a[l].cnt==0ll){
			l++;
			sum--;
		}
		if(a[r].cnt==0ll){
			r--;
			sum--;
		}
		if(sum==1) break;
	}
	cout << ans << "\n";
	return 0;
}
