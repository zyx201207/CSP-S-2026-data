#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=0,se=0,th=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}