#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[200010];
void f(int c,int y,int r){
	if(c=m){
		for(int i=r;i<=n;i++){
			ma=max(ma,(y&a[i]));
		}
		return;
	}
	else{
		for(int i=r;i<=n;i++){
			f(c++,(y&a[i]),r++);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(1,a[i],2);
	}
	cout<<ma;
	return 0;
}
