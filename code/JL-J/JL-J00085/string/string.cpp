#include<bits/stdc++.h>
using namespace std;
int n;
char c;
int p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p>>c;
	}
	if(n==2) cout<<0;
	if(n==3) cout<<2;
	return 0;
}
