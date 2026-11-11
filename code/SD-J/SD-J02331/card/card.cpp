#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int t[N],a[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=m;++i){//!
		s[i]=s[i-1]+t[i];
	}
	for(int i=1;i<=m;++i){
		cout<<s[i]<<' ';
	}
	return 0;
}
