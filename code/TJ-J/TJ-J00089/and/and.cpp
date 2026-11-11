#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,m,a[200005],maxx,maxnum,mmaaxx;
bool Sp1 = true,Sp2 = true;//特殊性质1,2 
bool ispow2(int x){
	int ans = 1;
	while(ans <= x){
		if(x == ans) return true;
		ans *= 2;
	}
	return false;
}
int getpow(int x){
	int ans = 1,num = 0;
	while(ans < x){
		ans *= 2;
		num++;
	}
	return num;
}
void dfs(int pos,int len,int num){//dfs骗分 
	if(len == m){
		maxx = max(maxx,num);
		return;
	}
	if(num < maxx) return;
	for(int i = pos+1;i <= n - (m - len) + 1;i++){
		dfs(i,len+1,a[i] & num);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(!ispow2(n)){
		Sp2 = false;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mmaaxx = max(mmaaxx,a[i]);
		if(!Sp1 or !ispow2(a[i]+1)){
			Sp1 = false;
		}
		if(!Sp2 or a[i] != i - 1){
			Sp2 = false;
		}
	}
	if(m == 1){
		cout << mmaaxx;
		return 0;//隐含的特殊性质 
	}
	if(Sp1){
		sort(a+1,a+n+1);
		cout << a[n - m + 1];
		return 0;
	}if(Sp2){
		cout << n - pow(2,getpow(m));
		return 0;
	}
	for(int i = 1;i <= n - m + 1;i++){
		if(a[i] >= maxx) dfs(i,1,a[i]);
	}
	cout << maxx;
	return 0;
}
