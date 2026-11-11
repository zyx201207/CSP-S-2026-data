#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[114514];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int s=a[1];
	for(int i=2;i<=m;++i){
		s=s and a[i];
	}
	cout<<a[n];
	return 0;
}
