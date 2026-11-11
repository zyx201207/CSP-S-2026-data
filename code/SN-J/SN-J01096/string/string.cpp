#include<iostream>
#include<cmath>
using namespace std;
int main(){
	char a,c,e,g;
	int b,d,f;
	cin >> a >> b >> c >> d >> e >> f >> g;
	int k=min(f,b);
	if(b==f&&c==g){
		cout << "0";
	}else if(d%2==0){
		cout << k+1;
	}else{
		cout << k;
	}
	return 0;
}
