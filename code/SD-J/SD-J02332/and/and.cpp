#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int maxx=LLONG_NIN;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n==1){
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
	}else if(m==n){
		int x=a[i];
		for(int i=1;i<=n;i++) x=x&a[i];
		cout<<x;
	}else if(m==2){
		for(int i=1;i,=n;i++){
			for(int j=i+1;j<=n;j++) maxx=(max,a[i]&a[j])
			cout <<maxx;
		}
	}
	else if(flag) cout<<n-m;
	else cout<<n-m-1;
	return 0;
}
