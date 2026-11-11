#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0;
	long long m=0;
	cin>>n>>m;
	int k=0;
	int a=0;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>k){
			k=a;
		}
	}
	if(m==n){
		cout<<k;
	}
	
	
	
	return 0;
}
