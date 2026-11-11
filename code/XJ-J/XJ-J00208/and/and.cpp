#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<m;i++){
		ans=a[i]&a[i+1];
	}
	cout<<ans;
	return 0;
}
