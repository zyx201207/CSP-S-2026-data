#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5;
int a[N];
LL n,m,maxn=-1e9;
int max_(LL X,LL Y){
	if(X>Y){
		return X;
	}else{
		return Y;
	}
}
void dfs(LL ma_x,int c,int op){
	if(c==m){
		maxn=max_(ma_x,maxn);
		return;
	}
	if(op>n)return;
	LL x=ma_x;
	if(c==0){
		x=a[op];
	}else{
		x=x&a[op];
	}	
	dfs(x,c+1,op+1);
	dfs(ma_x,c,op+1);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	dfs(0,0,1);
	cout<<maxn;
	return 0;
}
