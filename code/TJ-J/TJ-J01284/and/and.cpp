#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x>y;
}
const int N=2e5+1;
int n,m,res;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	res=a[1];
	for(int i=2;i<=m;i++){
		res=res&a[i];
	}
	cout<<res;
	return 0;
}
