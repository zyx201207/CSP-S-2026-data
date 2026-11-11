#include <iostream>
using namespace std;
int main(){
	int n,sum=0,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(n==i){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}