#include<bits/stdc++.h>
#define pii pair<long long,char>
using namespace std;
const int N = 2e5 + 10;
long long n, cnt, cnt1,len;
long long x[N], st[N], e[N], st1[N], e1[N],l,r,a[N],rs,res,ans;
char c[N],ch[N];
int f,fi,ff;
vector<pii> v, v1;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	v1.push_back({0,0});
	v.push_back({0,0});
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> c[i];
		st1[i] = cnt1 + 1;
		cnt1 += x[i];
		e1[i] = cnt1;
		v1.push_back({x[i], c[i]});
	}
	for (int i = 1; i <= n; i++) {
		//cout << st1[i]<< " " << e1[i] << endl;
	}
	st1[1] = 1;
	if(cnt1 % 2 == 1) f = 1;
	for (int i = 1, j = 1; i <= n; i++,j++) {
		if(st1[i] <= cnt1 / 2 && cnt1 / 2 < e1[i] && fi == 0) {
			st[j] = cnt + 1;
			cnt = cnt1 / 2;
			e[j] = cnt1 / 2;
			v.push_back({cnt1 / 2 - st[j] +1, c[i]});
			j++;
			//cout << st[j - 1]<< " " << e[j- 1] << " " << v[j - 1].first << " " << v[j - 1].second << j -1 <<endl;
			if(f == 1) {
				st[j]= cnt1 / 2 + 1;
				cnt = cnt1 / 2 + 1;
				e[j] = cnt1 / 2 + 1;
				j++;
				v.push_back({1, c[i]});
				//cout << st[j - 1]<< " " << e[j - 1] << " " << v[j -1].first << " " << v[j -1].second << j - 1<<endl;
			}
			if(e1[i] >= cnt1 / 2 + 1) {
				st[j]= cnt1 / 2 + 2;
				if(f!= 1) st[j]--;
				cnt = e1[i] ;
				e[j] = e1[i];
				j++;
				v.push_back({e1[i] - (cnt1 / 2 + 1) +(1-f), c[i]});
			}
			fi = 1;
			i++;
			//cout << st[j-1]<< " " << e[j-1] << " " << v[j-1].first << " " << v[j-1].second << j - 1<<endl;
		}
		//cout << st[j] << " " <<e[j] << cnt<< endl;
		//cout << cnt << 666;
		st[j] = cnt + 1;
		cnt += x[i];
		e[j] = cnt;
		v.push_back({x[i], c[i]});
		//cout << st[j]<< " " << e[j] << " " << v[j].first << " " << v[j].second <<j<< endl;
	}
	for (int j = 1; j < v.size(); j++) {
		cout << st[j]<< " " << e[j] << " " << v[j].first << " " << v[j].second << endl;
		a[j] = v[j].first;
		ch[j] = v[j].second;
	}
	len = v.size();
	if(f == 1) {
		l = len / 2;
		r = len/ 2 + 2;
	} else {
		l = len/ 2, r = len/ 2 + 1;
	}
	//ans = cnt1 / 2;
	while(l !=0 && r != n + 1) {
		if(ch[l] == ch[r]) continue;
		if(a[l] > a[r]) {
			rs = a[r];
			a[l] -= a[r];
			r++;
		} else if(a[l] == a[r]) {
			rs = a[r];
			a[l] -= a[r];
			l--, r++;
		} else {
			rs = a[l];
			a[r] -= a[l];
			l--;
		}
		ans += rs;
	}
	cout << ans;
	return 0;
}
