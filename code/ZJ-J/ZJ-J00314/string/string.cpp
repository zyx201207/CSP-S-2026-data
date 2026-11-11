#include <bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}q[200005];
int n;
long long cnt=0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int k=1, l=n;
	for(int i = 1; i <= n; i ++){
		cin >> q[i].a >> q[i].c;
	}
	int i=1, j=n;
	while(i < j){
		if(q[i].a == q[j].a){
			if(q[i].c != q[j].c) cnt += q[j].a;
			i ++;
			j --;
		}
		else if(q[i].a > q[j].a){
			if(q[i].c != q[j].c) cnt += q[j].a;
			q[i].a -= q[j].a;
			j --;
		}
		else{
			if(q[i].c != q[j].c) cnt += q[i].a;
			q[j].a -= q[i].a;
			i ++;
		}
	}
	cout << cnt;
	return 0;
}