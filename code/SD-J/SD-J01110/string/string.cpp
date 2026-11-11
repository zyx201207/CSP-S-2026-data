#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans;
struct node{
	int cnt;
	char c;
}a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].cnt >> a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].cnt<a[r].cnt){
				a[r].cnt-=a[l].cnt;
				l++;
			}else if(a[l].cnt>a[r].cnt){
				a[l].cnt-=a[r].cnt;
				r--;
			}else{
				l++,r--;
			}
		}else{
			if(a[l].cnt<a[r].cnt){
				ans+=a[l].cnt;
				a[r].cnt-=a[l].cnt;
				l++;
			}else if(a[l].cnt>a[r].cnt){
				ans+=a[r].cnt;
				a[l].cnt-=a[r].cnt;
				r--;
			}else{
				ans+=a[l].cnt;
				l++,r--;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
