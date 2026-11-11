#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) cnt=a[1];
		cnt=cnt&a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		cout<<(a[n]&a[n-1]);
		return 0;
	}
	if(m==n){
		cout<<cnt;
		return 0;
	}
	return 0;
}
