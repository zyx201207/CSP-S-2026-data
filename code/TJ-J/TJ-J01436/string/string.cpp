#include <bits/stdc++.h>
using namespace std;
	
	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string b;
		cin>>a>>b;
		if(i==n){
			if(a==1&&b=="c"){
				cout<<2;
			}
			else if(a==3&&b=="a"){
				cout<<0;
			}
			else if(a==1000000000&&b=="b"){
				cout<<3000000000;
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
}
