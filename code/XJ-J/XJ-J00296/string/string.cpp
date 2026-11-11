# include <bits/stdC++.h>
using namespace std;
int N=1005;
int main (){
	int a,d,x,y,z;
	char ABC[N];
	for(int i=0;i<=1005;i++){
		ABC[i]=' ';
	}
	cin>>a;
	cin>>x;
	char o;
	cin>>o;
	for(int i=0;i<=x;i++){
		ABC[i]=o;
	}
	cin>>y;
	cin>>o;
	for(int i=x;i<=y;i++){
		ABC[i]=o;
	}
	cin>>z;
	cin>>o;
	for(int i=x+y;i<=z;i++){
		ABC[i]=o;
	}
	char cba[N];
	for(int i=1005;i>=0;i--){
		cba[i]=ABC[d];
		d++;
	}
	if(cba[1005]==ABC[1]){
		cout<<0;
	}
	
	return 0;
}