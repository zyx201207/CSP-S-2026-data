#include<bits/stdc++.h>
using namespace std;
int a[200050];
int cmp(int x1,int x2){ //´óµ½Ð¡ 
	return x1>x2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int sum=a[1];
	for(int i=1;i<=m;i++) sum=sum&a[i];
	cout<<sum;
	return 0;
} 
