#include<bits/stdc++.h>
using namespace std; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
		freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001],sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}
