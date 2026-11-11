#include <iostream>
using namespace std;
int main(){
	int n,a,c[1000],sum=0;
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==c[i+1]){
			sum+=0;
		}
		else{
			sum+=a;
		}
	}
	cout>>sum;
	return 0;
}