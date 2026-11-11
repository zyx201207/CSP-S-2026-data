#include <bits/stdc++.h>
#define int long long
int n,d; 
const int MAXN=1e6+5;

int a[MAXN];
int qwq=0,ii=0;
int calc(int i,int j){
	if(i>=j){
		return 0;
	}
	std::vector<int> v;
	for(int k=i+1;k<=j;k++){
		if(llabs(a[k]-a[i])<=d){
			int res=calc(k,j)+1;
			v.push_back(res);
		} 
	}
	int minn=4e18;
	for(auto x:v)minn=std::min(minn,x);
	if(i==ii){
		for(auto x:v){
			qwq+=(x==minn);
//			std::cout<<minn<<' '<<x<<i<<' '<<j<<'\n';
		}
	}
	return minn;
} 
void solve(){
	std::cin>>n>>d;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			qwq=0;
			ii=i;
			calc(i,j);
			if(qwq==2){
				tot++;
			}
		}
	}
	std::cout<<tot<<'\n';
//	   return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	std::cin>>c>>t;
	while(t--){
		solve();
	} 
	return 0;
} 
//记得开-O2 -Wall -Wextra!
//放松心态
//原神，启动！
//暴力可能写挂了 
