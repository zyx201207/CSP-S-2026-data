#include <bits/stdc++.h>
using namespace std;
string a[2],b[2];
bool x=1,xp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a[0];
	cin >> b[0];
	cin >> a[1];
	cin >> b[1];
	if(a[0]!=a[1]){
		cout << "0000";
		return 0;
	}
	else cout << 1; 
	if(b[0][0]!=b[1][0] || b[0][1]!=b[1][1]){
		cout <<"000";
		return 0;
	} 
	else{
		cout <<1;
	}
	if((b[0][2]<=67&&b[1][2]>67)||(b[0][2]>67&&b[1][2]<=67) || x==0){
		cout <<"00";
		x=0; 
		return 0;
	} 
	else cout <<1;
	if((abs(b[0][2]-b[1][2])==1) && (x==1)) cout <<1;
	else cout <<0;
	return 0; 
}
