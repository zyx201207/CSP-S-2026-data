#include<bits/stdc++.h>
using namespace std;
int a[500000+5];
int check(int x){
	int sum=0,mx=a[x];
	for(int i=1;i<=x;i++){
		sum+=mx-a[i];
	}
	return sum;
}
int main(){
	frepoen("crystal.in","r",stdin);
	freopen("crystal.out","w",sdtout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n,mid=(l+r)/2,ans=0;
	while(l<)
	return 0;
}
