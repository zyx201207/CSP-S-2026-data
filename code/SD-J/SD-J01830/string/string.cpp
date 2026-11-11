#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N = 1e6 + 10;
struct node {
	int num;
	char c;
} a[N];
int n,m,ans;
//priority_queue
//lower_bound upper_bound
void solve() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	while(l<r) {
		if(a[l].c==a[r].c) {
			if(a[l].num>a[r].num) {
				a[l].num-=a[r].num;
				r--;
			} else if(a[l].num==a[r].num) {
				l++,r--;
			} else if(a[l].num<a[r].num) {
				a[r].num-=a[l].num;
				l++;
			}
		} else {
			if(a[l].num>a[r].num) {
				a[l].num-=a[r].num;
				ans+=a[r].num;
				r--;
			} else if(a[l].num==a[r].num) {
				ans+=a[l].num;
				l++,r--;
			} else if(a[l].num<a[r].num) {
				a[r].num-=a[l].num;
				ans+=a[l].num;
				l++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _ = 1;
//	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}
/*
B:双指针
思路：不用拼接
	每次将开头和结尾的两个的num比较；
	num大的-=num小的;
	if当前的c不同->ans+=num小
	num对应的指针++或--；
	当l==r结束
*/
