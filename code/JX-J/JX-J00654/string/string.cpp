#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int n,LEN,cnt;
int a[N],pre[N],suf[N],suf2[N];
char c[N];
void f(){
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++){
		sum += a[i];
		if(sum >= (LEN + 1) / 2){
			a[i] --,LEN --;
			return;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] >> c[i],LEN += a[i];
	if(LEN % 2 == 1) f();
	//for(int i = 1 ; i <= n ; i ++)
	//	cout << a[i] << ' ' << c[i] << '\n';
	for(int i = 1 ; i <= n ; i ++) pre[i] = pre[i - 1] + a[i];
	for(int i = n ; i >= 1 ; i --) suf[i] = suf[i + 1] + a[i];
	for(int i = 1 ; i <= n ; i ++) suf2[i] = suf[n - i + 1];
	int j = n,tt = 1;
	for(int i = 1 ; i <= n ; i ++){
		//cout << "\nROUND " << i << "\n";
		if(a[i] == 0) continue;
		int pos = pre[i],cl = c[i];
		int R = LEN - pos + 1;
		//cout << "pos=" << pos << "  R=" << R << '\n';
		int idx = n - (lower_bound(suf2 + 1,suf2 + n + 1,pos) - suf2) + 1;
		//cout << "idx=" << idx << '\n';
		//cout << "for j: \n";
		for( ; j > idx ; j --){
			//cout << "j=" << j << "  tt=" << tt << '\n';
			int dis = suf[j] - tt + 1;
			if(cl == c[j]) cnt += dis;
			tt = suf[j] + 1;
		}
		j = idx;
		if(cl == c[idx]) cnt += pos - tt + 1;
		if(R == suf[idx]) j --;
		tt = pos + 1;
		//cout << i << ' ' << cnt << '\n';
	}
	//cout << "\n\n";
	cout << (LEN - cnt) / 2;
	return 0;
}
//RP ++
//Luogu @zzhengxi
