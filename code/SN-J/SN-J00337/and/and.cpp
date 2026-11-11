#include<bits\stdc++.h>
using namespace std;
int n,m,a[200005];
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1,c);
	cout<<a[2];;
	return 0;
}
