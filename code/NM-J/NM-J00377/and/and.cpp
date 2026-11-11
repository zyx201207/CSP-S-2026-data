#include <bits/stdc++.h> 
using namespace std;

int n,m;
int a[10000001];
int t,s = 0;
int ans;

int solve(int x){
	for(int i = x;i <= n;i++){
		if(s == m){
			break;
		}
		t &= a[i];
		s++;
		solve(i+1);
	}
	ans = max(ans,t);
	t = 0;
	return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	solve(1);
	printf("%d",ans);
	return 0;
}
