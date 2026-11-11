#include<bits/stdc++.h>
using namespace std;
long long n, len, l, cnt, u, v;
string s;
struct node{
	long long a, lf, rt;
	string s;
}q[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>q[i].a>>q[i].s;
		q[i].lf = len + 1;
		len += q[i].a;
		q[i].rt = len;
	}
	l = 1;
	u = 1;
	v = n;
	while(l * 2 <= len){
		while(q[u].rt < l){
			u++;
		}
		while(q[v].lf > len + 1 - l){
			v--;
		}
		if(q[u].s != q[v].s){
			cnt += min(q[u].a, q[v].a);
		}
		l += min(q[u].a, q[v].a);
		if(q[u].a < q[v].a){
			q[v].a -= q[u].a;
			q[u].a = 0;
		}
		else{
			q[u].a -= q[v].a;
			q[v].a = 0;
		}
	}
	cout<<cnt;
	return 0;
}



