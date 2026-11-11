#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string str;
	long long n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a=0;
		cin>>a;
		char b='\0';
		cin>>b;
		for(int j=0;j<a;j++){
			str+=b;
		}
	}
	int z=str.length()/2;
	long long x=0;
	for(int i=0;i<z;i++){
		if(str[i]!=str[str.length()-i-1]){
			x++;
		}
	}
	cout<<x;
	return 0;
} 
