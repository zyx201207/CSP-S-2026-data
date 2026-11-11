#include <iostream>
using namespace std;
int main(){
	int m,s;
	long long sum=0;
	cin>>m;
	char a[50];
	int b[50];
	for(int i=0;i<m;i++){
		char n;
		cin>>s>>n;
		a[i]=n;
		b[i]=s;
	}
	for(int j=0;j<m/2;j++){
		if(a[j]!=a[m-1]){
			sum+=b[j];
		}
		else{
			sum+=0;
		}
	}
	cout<<sum;
	return 0;
} 
