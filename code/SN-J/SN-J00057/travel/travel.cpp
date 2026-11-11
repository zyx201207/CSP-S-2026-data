#include<iostream>
using namespace std;
int c[100];
int main(){
	freopen("and.in","a,b",stdin);
	freopen("and.out","c",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i>=a;i++){
		cin>>c[i];
	}
		for(int i=1;i<=2;i++){
			if(c[i]+c[i+1]<=c[i]+c[i+2]){
				cout<<c[3];
			}else if(c[i]%2!=0){
				cout<<c[i];
			}
		}
		cout<<c[3];
	return 0;
} 
