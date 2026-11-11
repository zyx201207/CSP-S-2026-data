//crystal
//RP++
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
ll n,m;

//等差数列 
void solveAB(){
	//填平 
	int i;
	for(i=2;i<=n;i++){
		//计算差值
		ll d=a[i]-a[i-1]; 
		//剩余操作次数可以将[1,i]填平
		if(m>=d*(i-1)){
			//计算经过操作后还剩余的操作数
			m-=d*(i-1);
			if(m==0) break;
		}
		//不能填平
		else break; 
	}
	ll len=i;
	for(int j=i;j<=n;j++){
		if(a[j]==a[i]) len=j;
		else break;
	} 
	cout<<len;
	return;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	ll diff=a[2]-a[1];
	bool flag=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=diff) flag=0;
	} 
	if(flag) solveAB();
	else if((a[n]-a[1])*n<=m){
		cout<<n;
		return 0;
	}
	else solveAB();
	return 0;
} 
//AFO
