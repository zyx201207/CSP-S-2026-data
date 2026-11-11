# include <bits/stdC++.h>
using namespace std;
int main (){
	char c1,c2,c3,c4;
	char a[10],b[10];
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>a[i];
	}
	cin>>c3;
	for(int i=1;i<=2;i++){
		cin>>b[i];
	}

	if(c1==c3){
		cout<<1;
	
	}
	else {
		cout<<0;
	}
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}