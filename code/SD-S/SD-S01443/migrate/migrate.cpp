#include <bits/stdc++.h>
using namespace std;
long long A[1001000],n,m;
long long dfs(long long x){
	long long i,j = abs(A[x] - A[x + 1]);
	for(i = x;i < m * 2 + x - 1;i++){
		if(abs(A[i + 1] - A[i]) != j){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long i,c,x,j,cnt = 0;
	cin>>c>>x;
	while(x--){
		cin>>n>>m;
		for(i = 1;i <= n;i++){
			cin>>A[i];
		}
		if(n >= m){
			long long t = n - (m * 2) + 1;
			for(i = 1;i <= t;i++){
				if(dfs(i) == 1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		cnt = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
