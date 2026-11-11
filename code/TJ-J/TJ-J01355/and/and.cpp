#include<bits/stdc++.h>
using namespace std;
bool mysort(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,mysort);
	int ans=a[0];
	for(int i=0;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
