#include<bits/stdc++.h>
using namespace std;
const int N=1e5*3;
int a[N];
int ans;
bool st(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,st);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	} 
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
