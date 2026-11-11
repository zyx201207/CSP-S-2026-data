#include<iostream>
using namespace std;
int main(){
	int n[10005],i;
	for(int j=1;j<=n;j++){
		cin>>i;
		if(n%i==2&&i%j==1){
			cout<<i;
		}
	}
	return 0;
}
