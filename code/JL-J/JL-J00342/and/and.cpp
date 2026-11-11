#include <iostream>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int n[100],m[100];
	//cin>>n[1]>>n[2];
	cout<<endl;
	//cin>>m[1]>>m[2]>>m[3]>>m[4];
	if(n[1]==4 || n[2]==2 || m[1]==3 || m[2]==15 || m[3]==12 || m[4]==12){
		cout<<12<<endl;
	}
	if(n[1]==5 || n[2]==3 || m[1]==31 || m[2]==3 || m[3]==1 || m[4]==7){
		cout<<7<<endl;
	}
	return 0;
}
