#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
bool updel(int del[],int n){
	int max1=0;
	for(int i=0;i<n;i++){
		max1=max(max1,del[i]);
	}
	if(max1==0){
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int cost=m;
	int ans=0;
	int del[n];
	for(int i=1;i<n;i++){
		del[i]=a[i]-a[i-1];
	}
	if(updel(del,n)){
		cout<<n;
		return 0;
	}
	for(int i=n/2+1;i<n;i++){
		if(a[n/2]-a[i]<=cost && a[n/2]!=a[i]){
			cost-=a[n/2]-a[i];
			ans++;
		}
	}
	for(int i=0;i<=n;i++){
		if(a[i]==a[n/2]){
			ans++;
		}
	}
	cout<<ans;
}	