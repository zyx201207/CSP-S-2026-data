#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int a[200005]; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int c=a[1];
	for(int i=1;i<=m;i++){
		c=c&a[i];
	}
	cout<<c;
	return 0;
}
