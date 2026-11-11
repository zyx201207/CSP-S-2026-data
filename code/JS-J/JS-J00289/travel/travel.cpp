#include <bits/stdc++.h>;
using namespace std;
int Rc,Rl,Rsi,Rv,Xc,Xl,Xsi,Xv;
string rc,rs,xc,xs;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc >> rs >> xc >> xs;
    Rc=(rc[0]-'0')*10+(rc[1]-'0');
    Xc=(xc[0]-'0')*10+(xc[1]-'0');
    Rl=(rs[0]-'0')*10+(rs[1]-'0');
    Xl=(xs[0]-'0')*10+(xs[1]-'0');
    if (rs[2]>='A'&&rs[2]<='C'){
		Rsi=1;
	}
	else{
		Rsi=2;
	}
    if (xs[2]>='A'&&xs[2]<='C'){
		Xsi=1;
	}
	else{
		Xsi=2;
	}
	Rv=(rs[2]-'A'+1);
	Xv=(xs[2]-'A'+1);
	if (Rc==Xc){
		cout << "1";
		if (Rl==Xl){
			cout << "1";
			if (Rsi==Xsi){
				cout << "1";
				if (max(Rv,Xv)-min(Rv,Xv)==1){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
			    cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
	    cout << "0000";
	}
    return 0;
}
