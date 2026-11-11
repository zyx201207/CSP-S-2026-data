#include<bits/stdc++.h>
#define ll long long
//rp++
//lian biao
using namespace std;

const int N = 5e5 + 10;
struct node{
	int v, p;
};
int n, m, a[N], l[N], r[N], cnt[N], v[N];
node t[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++)
			l[j] = j - 1, r[j] = j + 1, v[j] = 0;
		r[n] = 0, r[i - 1] = i;
		for(int j = 1;j <= m;j ++)
			t[j].v = 0;
		for(int j = i;j <= n;j ++){
			if(t[a[j]].v == 1){
				int pos = t[a[j]].p;
				r[pos] = j;
				l[j] = pos;
				t[a[j]].p = pos;
			} else {
				t[a[j]].v = 1;
				t[a[j]].p = j;
			}
		}
		for(int j = 1;j <= m;j ++)
			t[j].v = 0;
		for(int j = i;j <= n;j ++){
			if(t[a[j]].v == 1){
				int pos = t[a[j]].p;
				r[pos] = j;
				l[j] = pos;
				t[a[j]].p = pos;
			} else {
				t[a[j]].v = 1;
				t[a[j]].p = j;
			}
		}
		
//		cout << r[i - 1] << ' ';
//		for(int i = 1;i <= n;i ++)
//			cout << r[i] << ' ';
//		cout << "\n";
//		cout << "\n";
//		for(int i = 1;i <= n;i ++)
//			cout << l[i] << ' ';
//		cout << "\n";
//		for(int i = 1;i <= n;i ++)
//			cout << r[i] << ' ';
//		cout << "\n";
		int cur = r[i - 1];
		while(cur){
			if(v[a[cur]] == 0) cnt[a[cur]] ++;
			v[a[cur]] = 1;
//			cout << cur << ' ' << a[cur];
//			cout << "\n";
			cur = r[cur];
		}
//		cout << "\n";
	}
	for(int i = 1;i <= m;i ++)
		cout << cnt[i] << ' ';
	return 0;
}

