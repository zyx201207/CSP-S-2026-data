#include<bits/stdc++.h>
using namespace std;
const int N(5e5+5);
int n,m,a[N],b[N],s[N];
void solve(){
	for(int i=n;i>=2;i--){
		if(b[i]<=m){
			cout<<i;
			return;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		b[i]=a[i]*(i-1)-s[i-1];
	}
	solve();
	return 0;
}