#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],k;
bool Ok_for_A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return 0;
		}
	}
	return 1;
}
bool Ok_for_B(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			return 0;
		}
	}
	return 1;
}
void solve1(){
	while(m>=0){
		m-=(k+1);
		k++;
	}
	cout<<min(k,n-1);
}
void solve2(){
	if(a[2]-a[1]==0){
		cout<<n-1;
		return;
	}
	int x=a[2]-a[1];
	while(m>=0){
		m-=x*(k+1);
		k++;
	}
	cout<<min(k,n-1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(Ok_for_A()){
		solve1();
	}
	else if(Ok_for_B()){
		solve2();
	}
	return 0;
}
