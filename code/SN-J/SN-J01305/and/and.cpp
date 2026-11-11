#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],ans[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out",'w',stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>n-m;i--){
		maxx=a[i+1]&a[i];
	}
	cout<<maxx;
	return 0;
}
