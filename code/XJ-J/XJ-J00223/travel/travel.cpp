#include<bits/stdc++.h>
using namespace std;
string a,x,b,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> x >> b >> y;
	string n="",m="";
	if(a==b){
		cout << 1;
    	if(x[0]==y[0]&&x[1]==y[1]){
			cout << 1;
			n+=x[2];
			m+=y[2];
			string r="F",l="D",r1="C",l1="A";
			if((n>=l&&m<=r&&n<=r&&m>=l)||(n>=l1&&m<=r1&&n<=r1&&m>=l1)){
				cout << 1;
				if(x[2]+1==y[2]||x[2]-1==y[2]){
					cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
