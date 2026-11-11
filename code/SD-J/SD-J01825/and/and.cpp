#include <bits/stdc++.h>
using namespace std;
long long A[30101],n,m,res = 0,ans,T[30101],book[30101];
long long check(){
	long long i,j,ans;
	ans = T[1];
	for(i = 2;i <= m;i++){
		ans = ans & T[i];
	}
	return ans;
}
void dfs(long long step){
	long long i,j,cncn;
	if(step == m + 1){
		cncn = check();
		res = max(res,cncn);
		return ;
	}
	for(i = 1;i <= n;i++){
		if(book[i] == 0){
			book[i] = 1;
			T[step] = A[i];
			dfs(step + 1);
			book[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j;
	cin>>n>>m;
	for(i= 1;i <= n;i++){
		cin>>A[i];
	}
	dfs(1);
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
