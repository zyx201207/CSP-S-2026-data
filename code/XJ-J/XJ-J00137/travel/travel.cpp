//travel
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
string a,aa,b,bb;
int main(){
	/**/
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> a >> aa >> b >> bb;
	if(a==b){
		//cout << 1;
		if(aa[0]==bb[0] && aa[1]==bb[1]){
			//cout << 1;
			if(aa[2]<='C'&&bb[2]<='C' || aa[2]>'C'&&bb[2]>'C'){
				//cout << 1;
				if(abs(aa[2]-bb[2])==1){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
