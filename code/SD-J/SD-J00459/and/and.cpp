#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200002];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int x=a[1];
	for(int i=1;i<=m;i++){
		x&=a[i];
	}
	for(int j=2;j<=n;j++){
		int y=a[j];
		for(int i=j+1;i<=j+m-1;i++){
			y&=a[i];
		}
		if(x>y){cout<<x;return 0;}
		else x=y;
	}
	return 0;
}
