#include <bits/stdc++.h>
using namespace std;
bool check(int x,int n,long long m,const vector<long long>& a){
	for(int i=0;i<x;i++){
		m-=a[x-1]-a[i];
	}
	if(m>=0) return 1;
	for(int i=x;i<n;i++){
		m+=a[i-1]-a[i-x];
		m-=(a[i]-a[i-1])*(x-1);
		if(m>=0) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int l=1,r=n;
	while(l<r){
		int x=(l+r+1)/2;
		if(check(x,n,m,a)){
			l=x;
		}else{
			r=x-1;
		}
	}
	cout<<l<<'\n';
	cout.flush();
	return 0;
}
