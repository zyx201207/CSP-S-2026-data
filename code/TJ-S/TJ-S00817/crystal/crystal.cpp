#include<bits/stdc++.h>
using namespace std;
long long n, m, mx, l, r, cnt;
struct node{
	long long a, diff;
}q[500005];
bool cmp(node i, node j){
	return i.a < j.a;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>q[i].a;
	}
	sort(q + 1, q + n + 1, cmp);
	for(int i = 2; i <= n; i++){
		q[i].diff = q[i].a - q[i - 1].a;
	}
	l = 2;
	r = 2;
	if(m > 1e9){
		cnt = 1;
		for(int i = 1; i <= n; i++){
			cnt *= 2;
			if(cnt > m) break;
			mx++;
		}
		cout<<mx;
		return 0;
	}
	while(r <= n){
		mx = max(mx, r + 1 - l);
		cnt += q[r].diff * (r + 1 - l);
		if(cnt > m){
			cnt -= (q[r].a - q[l].a);
			l++;
		}
		else{
			r++;
		}
	}
	cout<<mx;
	return 0;
}
