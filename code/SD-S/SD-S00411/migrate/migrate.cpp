#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
inline ll read(){
	ll x = 0 , f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
ll n,d,a[N],c,t,dis[N];
queue<int> q;
int dep[1000],cnt;
int di(int x){
	for(int i = 1; i <= n; i ++)
		dep[i] = 0x3f3f3f;
	dep[x] = 0;
	while(!q.empty())q.pop();
	q.push(x);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = 1; i <= n ; i ++){
			if(i == t)continue;
			if(abs(a[i]-a[t] )<= d){
				if(dep[i] <= dep[t])continue;
				dep[i] = min(dep[i],dep[t]+1);
				q.push(i);
			}
		}
	}
	return 0;
}
int dfs(int x,int y,int z,int nw){
	if(x == y&& z == nw){
		cnt++;
		return 0;
	}
	if(dep[x] >= z||nw >= z)return 0;
	for(int i = 1; i <= n ; i ++){
		if(i == x)continue;
		if(abs(a[x] - a[i]) <= d)
			dfs(i,y,z,nw + 1);
	}
	return 0;
}
int s1(){
	ll ans = 0;
	for(int i = 1 ; i <= n; i ++){
		di(i);
//		for(int l = 1 ;l <= n; l ++){
//			cout << dep[l] << " ";
//		}
//		cout << endl;
//	cout << "11111\n";
		for(int j = i + 1 ; j <= n ; j ++){
			if(j == i)continue;
			cnt = 0 ;
			if(dep[j] == 0x3f3f3f)continue;
			dfs(i,j,dep[j],0);
//			cout << i << " " << j << " " << cnt << endl;
			if(cnt == 2)ans ++;
		}
		
	}
	cout << ans <<"\n"; 
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read() , t = read();
	while(t--){
		n = read();d = read();
		for(int i = 1; i <= n; i ++)
			a[i] = read();
		if(n <= 20) 
		s1();
		else {
			cout << 0 << "\n";
		}
	}
	return 0; 
}
