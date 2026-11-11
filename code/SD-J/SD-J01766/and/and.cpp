#include <bits/stdc++.h>
using namespace std ;
long long ans1 = 0 ;
long long n,m,a[200005] ;
bool vis[200005] ;
bool cmp(long long x,long long y){
	return x>y ;
}
void f1(){
	long long mx = 0 ;
	for(int i=1;i<=n;i++){
		mx = max(mx,a[i]) ;
	}
	cout<<mx;
}
bool xza = true ;
//xza:每个数的二进制都全是1，找前m大的
bool xzb = true ;
//xzb:挑二进制都是1的 
void f2(){
	sort(a+1,a+1+n,cmp) ;
	cout<<a[m];
}
void f3(){
	long long cnt = 0;
	long long mn = 2147483648 ;
	for(int i=1;i<=n;i++){
		if(double(log2(a[i]+1))==int(log2(a[i]+1))){
			cnt++ ;
			mn = min(mn,a[i]) ;
			vis[i] = true;
		}
		if(cnt==m){
			cout<<mn ;
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) mn = min(mn,mn&a[i]) ;
	}
	cout<<mn;
}
void dfs(long long idx,long long now){
	if(idx==m+1){
		ans1 = max(ans1,now) ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = true ;
			dfs(2,now&a[i]) ;
			vis[i] = false ;
		}
	}
}
void f4(){
	for(int i=1;i<=n;i++){
		vis[i] = true ;
		dfs(1,a[i]) ;
		vis[i] = false ;
	}
}
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i] ;
		if(double(log2(a[i]+1))!=int(log2(a[i]+1))) xza = false;
		if(double(log2(n))!=int(log2(n))||a[i]!=i-1) xzb=false ;
	}
	if(m==1){
		f1() ;
	}
	else if(xza){
		f2() ;
	}
	else if(xzb){
		f3() ;
	}
	else{
		f4() ;
	}
	return 0 ;
} 
