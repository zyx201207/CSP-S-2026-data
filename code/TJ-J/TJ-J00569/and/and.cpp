#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,mx=0;
	cin>>a>>b;
	for(int i=1;i<a;i++){
		int q;
		cin>>q;
		mx=max(mx,q);
	}
	cout<<mx;
}
