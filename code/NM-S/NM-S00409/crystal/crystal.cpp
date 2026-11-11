 #include<bits/stdc++.h>
 using namespace std;
 int n,m,q[500010],a,op = 1,maxn = -1,b = 1;
 int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin >> n >> m;
 	for(int i = 1; i <= n; i ++) cin >> q[i];
 	sort(q + 1,q + n + 1);
 	for(int i = 1; i <= n; i ++){
 		if(a > m) break;
 		if(q[i] != q[i + 1]){
 			a += q[i + 1] - q[i];
 			if(a > m) break;
 			q[i] += q[i + 1] - q[i];
 			i = 0;
		 }
	 }
	 for(int i = 2; i <= n; i ++){
	 	if(q[i] == q[op]){
	 		b ++;
		 }
	 	else {
	 		maxn = max(b,maxn);
	 		op = i;
	 		b = 1;
		 }
	 }
	 cout << maxn;
 	return 0;
 }
