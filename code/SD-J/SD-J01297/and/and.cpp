#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int mx=0;
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	cout<<mx;
	return 0;
}
