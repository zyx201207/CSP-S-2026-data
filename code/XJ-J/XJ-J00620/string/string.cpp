#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	string h[10]=0,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			h[j]=b;
		}
	}
	cout<<h[10];
	return 0;
}
