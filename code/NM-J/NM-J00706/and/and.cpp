#include <iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a=0;
	int s=0;
	cin>>a>>s;
	int f=0;
	for(int i=0;i<a;i++){
		int d=0;
		cin>>d;
		if(i==a-1){
			f=d;
		}
	}
	cout<<f;
	return 0;
}
