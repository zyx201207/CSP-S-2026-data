#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,maxn,ans,cnt;
int a;
struct node{
	int l,a;
	char s[40];
}f[N];
/*
void ib(int x,int y){
	f[y].l = 0;
	f[y].a = x;
	/*while(x > 0){
		if(x % 2 == 1){
			f[y].s[f[y].l] = '1';
		}else{
			f[y].s[f[y].l] = '0';
		}
		f[y].l++;
		x /= 2;
	}
	
	return;
}
*/
bool cmp(node x,node y){
	return x.l >= y.l;
}
void dfs(int x,int y){
	if(x == 0){
		ans = max(ans,cnt);
		return;
	}
	for(int i = y;i <= n - x + 1;i++){
		if(x == m){
			cnt = f[i].a;
			dfs(x - 1,i + 1);
		}else{
			int a = cnt;
			cnt &= f[i].a;
			dfs(x - 1,i + 1);
			cnt = a;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a);
		maxn = max(maxn,a);
		f[i].a = a;
	}
	if(m == 1){
		printf("%d\n",maxn);
		return 0;
	}
	dfs(m,1);
	printf("%d\n",ans);
	return 0;
}
