#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005];
int cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[1];
//	for(int i=0;i<n;i++) cout<<a[i]<<"　";
	for(int i=0;i<m;i++){
		ans&a[i];
	}
	cout<<ans;
//qu xiao zhu shi
}
//4 2 3 15 12 12
