#include<bits/stdc++.h>
using namespace std;
int n,m,maxa=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		maxa=max(c,maxa);
	}
	cout<<maxa;
}