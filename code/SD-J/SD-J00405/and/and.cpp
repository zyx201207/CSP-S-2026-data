#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int erjinzhi(int a){
	int u=0;
	while(a!=0){
		u=a%2*10+u;
		a=(a-a%2)/2;
	}
	return u;
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=erjinzhi(a[i]);
	}
	cout<<a[1];
	return 0;
}

