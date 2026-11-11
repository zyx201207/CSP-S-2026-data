#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=2e5+100;
ll n,m,a[N];
string ejz1(ll x){
	string s="";
	while(x>0){
		if(x%2==1) s='1'+s;
		else s='0'+s;
		x/=2;
	}
	return s;
}
string yu(string x,string y){
	string s="";
	while(x.size()<y.size()) x='0'+x;
	while(x.size()>y.size()) y='0'+y;
	for(int i=0;i<x.size();i++){
		if(x[i]=='1' and y[i]=='1') s=s+'1';
		else s=s+'0';
	}
	return s;
}
int ejz2(string x){
	ll cnt=0;
	for(int i=x.size()-1;i>=0;i--){
		if(x[i]=='1') cnt+=pow(2,x.size()-i-1);
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	string ans=ejz1(a[n]);
	for(int i=n-1;i>n-m;i--){
		string b=ejz1(a[i]);
		ans=yu(b,ans);
	}
	cout<<ejz2(ans);
}
