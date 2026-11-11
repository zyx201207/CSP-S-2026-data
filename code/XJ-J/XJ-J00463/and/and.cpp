#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,d=-1,a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		d=max(d,a);
	}
	cout<<d;
	return 0;
}