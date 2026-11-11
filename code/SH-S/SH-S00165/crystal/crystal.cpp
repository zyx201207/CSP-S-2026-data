#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long num(long long x){
	long long ans=0,s=0;
	while(ans<x){
		s++;
		ans+=s;
	}
	return s;
}
bool sc=1,sa=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,p=1;
	long long m,s=1,f=0;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])sa=0;
	}
	if(sa){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==2){
		if(a[1]==a[2])cout<<2;
		else if(m==0)cout<<1;
		else cout<<2;
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])sc=0;
	}
	if(sc){
		s+=num(m/(a[2]-a[1]));
		cout<<s;
		return 0;
	}
	f=(a[p+1]-a[p])*p;
	while(m-f>=0&&p<=n){
		m-=f;
		s++;
		p++;
		f=(a[p+1]-a[p])*p;
	}
	cout<<s; 
	return 0;
}
