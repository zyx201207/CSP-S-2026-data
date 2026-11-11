#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s;
	int a[114514];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		if(i==n) s=a[n];
		s=s&a[i];
		cout<<s<<' ';
	}
	cout<<s;
	return 0;
}
