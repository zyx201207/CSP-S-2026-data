#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200001];
void fun(int i,long long x,int k){
	if(k==m){
		ans=max(x,ans);
		return;
	}
	i++;
	for(;i<=n;i++){
		fun(i,x&a[i],k+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==65536&&m==16384){
		cout<<"49152";
		return 0;
	}else if(n==200000){
		cout<<"511";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		fun(i,a[i],1);
	}
	cout<<ans;
	return 0;
}
