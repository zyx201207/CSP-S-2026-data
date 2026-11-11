#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 * 2 + 10;
int n,m;
long long ans;
long long a[N];
void dfs(int x,int i,long long an){
	if(x == m){
		ans = max(an,ans);
		return;
	}
	if(i == n) return ;#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 * 2 + 10;
struct Node{
	long long len,xb,ed;
	char c;
} a[N];
int n;
int main(){
	FIO
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	a[0].xb = a[0].len = 0;
	cin >> a[1].len >> a[1].c;
	a[1].xb = 1,a[1].ed = a[1].len;
	for (int i = 2;i <= n;i ++) {
		cin >> a[i].len >> a[i].c;
		a[i].xb = a[i - 1].xb + a[i - 1].len;
		a[i].ed = a[i].xb + a[i].len - 1;
	//	cout << a[i].xb << ' ' << a[i].ed<<endl;
	}
	long long mid = a[n].ed / 2 + a[n].ed % 2,ans = 0,r = n,l;	
//	cout << mid << endl;
	for(int i = 1; i<= n;i ++) {
		long long xx = max(a[n].ed - a[i].ed + 1,mid + 1);
		if(a[i].xb > mid) break;
		if(a[i].xb == mid){
			if(a[n].ed % 2 == 0 && a[i].len == 1 && a[i + 1].c != a[i].c) ans ++;
			break; 
		}   
		for(l = r;l >= i;l --)	if(a[l].xb <= xx && a[l].ed >= xx) break;
	//	cout << l << ' ' << r<<endl;
		if(l == r) {
			if(a[l].c != a[i].c) ans += a[i].len;
		//	cout << l << ' ' << i << endl;
		} else{
			for(int j = l;j <= r;j ++) {
				if(a[j].c != a[i].c){
					if(i == 1) ans += min(a[j].len,a[j].ed - xx + 1);
					else ans += min(a[j].ed,a[n].ed + 1 - a[i - 1].ed - 1) - max(xx,a[j].xb) + 1; 
				}
			}
		}
		if(xx == a[l].xb) r = l - 1;
		else r = l;
	}
	cout << ans;
}
	if(i - x > n - m) return;
	if(i - x + n - i  < n - m) return;
	if(x == 0){
		dfs(x + 1,i + 1,a[i + 1]);
		dfs(x,i + 1,an);
	}
	else{
		dfs(x + 1,i + 1,an & a[i + 1]);
		dfs(x,i + 1,an);
	}

}
int main(){
	FIO
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	if(m == 1){
		long long mx = 0;
		for(int i = 1;i <= n;i ++){
			mx = max(mx,a[i]);
		}
		cout << mx;
	} else if(m == n){
		ans = a[1];
		for(int i = 1;i <= n;i ++) ans &= a[i];
	} else if(m == 2 && n <= 2000){
		long long ans = 0;
		for(int i = 1; i<= n;i ++){
			for(int j = i + 1;j <= n;j ++) {
				long long b = a[i];
				b &= a[j];
				ans = max(ans,b);
			}
		}
		cout << ans;
	} else if(n <= 20){
		dfs(0,0,0ll);
		cout << ans;
	}
	
}