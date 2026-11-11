#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
	int c,t;
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		int n,d;
		cin>>n,d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++){
//				if()
//			}
//		}
		if(n%d==0){
			cout<<"2";
		}
		if(n%d>=n/d){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
} 