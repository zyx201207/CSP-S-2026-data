#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

