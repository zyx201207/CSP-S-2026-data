#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool px(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,px);
	int sum=a[1];
	for(int i=1;i<=m;i++){
		sum=(sum&a[i]);
	}cout<<sum;
	return 0;
}
