#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
typedef long long ll;
struct node{
	ll sz;
	char s;
}a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].sz >> a[i].s;
	}
	int tmp1 = 1;
	int tmp2 = n;
	ll cnt = 0;
	while(tmp1 < tmp2){
		ll sz1 = a[tmp1].sz;
		char s1 = a[tmp1].s;
		ll sz2 = a[tmp2].sz;
		char s2 = a[tmp2].s;
		if(s1 == s2){
			if(sz1 < sz2){//tmp1 xiao ++
				tmp1++;
				a[tmp2].sz -= sz1;
			}else if(sz2 < sz1){//tmp2 xiao --;
				tmp2--;
				a[tmp1].sz -= sz2;
			}else {//tmp1++ tmp2--;
				tmp1++;
				tmp2--;
			}
		}else if(s1 != s2){
			if(sz1 < sz2){//tmp1 xiao ++ cnt+= sz1;
				cnt += sz1;
				tmp1++;
				a[tmp2].sz -= sz1;
			}else if(sz2 < sz1){//tmp2 xiao -- cnt += sz2
				cnt += sz2;
				tmp2--;
				a[tmp1].sz -= sz2;
			}else {
				cnt += sz2;
				tmp1++;
				tmp2--;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
