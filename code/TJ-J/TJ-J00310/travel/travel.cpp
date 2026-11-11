#include <bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> b >> d;
	if(a != b){
		cout << "0000";
		return 0;
	}
	if(sizeof(c) != sizeof(d)){
		cout << "1000";
		return 0;
	}
	if(sizeof(c) == 1){
		if(c[0] != d[0]){
			cout << "1000";
			return 0;
		}
		if(!((c[1] == 'C'|| c[1] == 'B' || c[1] == 'A') && (d[1] == 'C'|| d[1] == 'B' || d[1] == 'A'))){
			cout << "1100";
			return 0;
		}
		if((c[1] == 'C' && d[1] == 'A') || (c[1] == 'A' && d[1] == 'C')){
			cout << "1110";
			return 0;
		}
		
	}
	else{
		if(c[1] != d[1]){
			cout << "1000";
			return 0;
		}
		if(!((c[2] == 'C'|| c[2] == 'B' || c[2] == 'A') && (d[2] == 'C'|| d[2] == 'B' || d[2] == 'A'))){
			cout << "1100";
			return 0;
			
		}
		if((c[2] == 'C' && d[2] == 'A') || (c[2] == 'A' && d[2] == 'C')){
			cout << "1110";
			return 0;
		}
	}
	cout << "1111";
	return 0;
}
