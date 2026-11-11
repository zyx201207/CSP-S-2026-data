#include<bits/stdc++.h>
using namespace std;
#define int long long
int c , t , n , d , tmp1 , Min1 , vis[2000005] , x[2000005] , flag[1005][1005] ;
void dfs(int s , int f , int co){
	if(s==f){
		if(co<Min1){
			Min1=co;
			tmp1=1;
		}else if(co==Min1)tmp1++;
	}
	for(int i=s+1;i<=f;i++){
		if(!vis[i]&&flag[s][i]){
			vis[i]=1;
			dfs(i,f,co+1);
			vis[i]=0;
		}
	}
}
void solve1(){
	int cnt=0 ;
	while(t--){
		cnt=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				flag[i][j]=flag[j][i]=0;
				if(x[j]-x[i]<=d)flag[i][j]=flag[j][i]=1;//,cout << i << " " << j << '\n' ;
			}
		}
		for(int i=1;i<n;i++){
			vis[i]=1;
			for(int j=i+1;j<=n;j++){
				tmp1=0;
				Min1=LLONG_MAX;
				dfs(i,j,0);
			//	cout << i << " " << j << " " << tmp1 << " " << Min1 << "!\n" ;
				if(tmp1==2)cnt++;//,cout << i << " " << j << "!\n" ;
			}
			vis[i]=0;
		}
		printf("%lld\n",cnt);
	}
}
struct Node{
	int l , r ;
}wide[2000005];
void solve2(){
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		int sign ;
		for(int i=1;i<=n;i++)//寻找第一个使得海鸟可以从该岛屿直接飞到任意其他岛屿的岛屿  
			if(x[i]-x[1]<=d&&x[n]-x[1]<=d){
				sign=i;
				break;
			}
		if(sign==1||sign==n){
			printf("0");
			return;
		}
//		int l=1 , r=sign+1 ;
//		while(l<sign||sign<r){
//			int tl=upper_bound(x+1,x+sign,x[l]+d)-x-1 ,
//				tr=upper_bound(x+2+sign,x+1+n,x[r]-d)-x-1 ;
//			if(tl==sign)tl--;
//			if(tr==sign)tr++;
//			if()
//		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	if(c==1||c==2){
		solve1();
	}else if(c==13||c==14){
		solve2();
	}
	return 0;
}
