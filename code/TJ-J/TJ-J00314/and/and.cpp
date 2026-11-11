#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long
LL n,m,a[200005];

LL dfs(LL now,LL step,LL n1){
	if(n - now == step){
		LL sum = a[now];
		for(int i = now + 1;i <= n1;i++){
			sum &= a[i];
		}
		return sum;
	}
	if(step == 0) return 0;
	LL y = a[now];
	if(step - 1 != 0){
		y &= dfs(now + 1,step - 1,n1);
	}
	return max(y,dfs(now + 1,step,n1));
}

int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n == m){
		LL sum = a[1];
		for(int i = 2;i <= n;i++){
			sum &= a[i];
		}
		cout<<sum;
		return 0;
	}
	LL maxn = dfs(1,m,n);
    cout<<maxn;
    
    return 0;
}
