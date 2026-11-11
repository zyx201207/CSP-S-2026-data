#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans1,ans2,ans;
int a[N],l[N],z[N];
int lowbit(int x){
	return x& -x;
}
int lbt(int x){
	int sum=0;
	while(x){
		sum++;
		x-=lowbit(x);
	}
	return sum;
}
int sw(int x){
	int sum=0;
	while(x){
		sum++;
		x=x>>1;
	}
	return sum;
}
bool cmp1(int a,int b){
	return lbt(a)>lbt(b);
}
bool cmp2(int a,int b){
	return a>b;
}
//string zz(int x){
//	string s="";
//	while(x){
//		if(x%2==1) s='1'+s;
//		else s='0'+s;
//		x/=2;
//	}
//	return s;
//}
void dfs(int x,int c,int k){
	if(k==m+1){
		ans=max(ans,c);
		return ;
	}
	if(x==n+1){
		return ;
	}
	dfs(x+1,c&a[x],k+1);
	dfs(x+1,c,k);
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cout<<lbt(16)<<" "<<sw(16)<<"\n";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,INT_MAX,1);
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+1+n,cmp1);
	ans1=a[1];
	for(int i=2;i<=m;i++){
		ans1&=a[i];
	}
	sort(a+1,a+1+n,cmp2);
	ans2=a[1];
	for(int i=2;i<=m;i++){
		ans2&=a[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<zz(a[1])<<"\n"<<zz(a[2])<<"\n"<<zz(a[3])<<"\n"<<zz(a[4])<<"\n";
	cout<<max(ans1,ans2)<<"\n";
//	cout<<ans2<<"\n";
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
