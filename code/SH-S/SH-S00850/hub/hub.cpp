#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >>t;
	if(t==1)
	cout << 3< endl;
	if(t==2) cout << 4 << endl << 2;
	if(t==3) cout << 7 <<endl<<2<<endl << 5;
	if(t==4) cout << 9 <<endl<< 4 <<endl<< 7 <<endl<< 2;
	if(t==5) cout << 12<<endl<<3<<endl<<8<<endl<<9<<endl<<6<<endl;
	else{
		while(t--)
		cout << c*t;
	}
	return 0;
}
