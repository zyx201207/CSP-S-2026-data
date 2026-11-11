#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],s[N];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	s[1]=a[1];
	for(int i=2;i<=m;i++){
		s[i]=(s[i-1]&a[i]);
	}
	cout<<s[m];
	return 0;
}

