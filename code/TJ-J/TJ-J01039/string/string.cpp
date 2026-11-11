#include <bits/stdc++.h>
using namespace std;
int n;
int a;
char t;
int hw(string z){
	int zlen=z.size();
	for(int i=0;i<zlen;i++){
		char p=z[i];
		if(p==z[i]){
			return 0;
		} 
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;

	string z;
	for(int i=1;i<=n;i++){
		cin>>a>>t;
		for(int j=1;j<=a;j++){
			z=z+t;
		}
	
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	cout<<hw(z);
	return 0;
}
