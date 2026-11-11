#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	getline(cin,s);
	
	for(int i=0;i<2;i++){
		rc+=s[i];
	}	
	for(int i=3;i<6;i++){
		rs+=s[i];
	}
	for(int i=7;i<9;i++){
		xc+=s[i];
	}
	for(int i=10;i<=12;i++){
		xs+=s[i];
	}
	if(rc==xc){
		cout << '1';
		if(rs[0]==xs[0] and rs[1]==xs[1]){
			cout << '1';
			if((rs[2]>='A' and rs[2]<='C' and xs[2]>='A' and xs[2]<='C') or (rs[2]>='D' and rs[2]<='F' and xs[2]>='D' and xs[2]<='F')){
				cout << '1';
				if((abs(rs[2]-xs[2])==1) or ((abs(rs[2]-xs[2])==1) and (rs[2]>='D' and rs[2]<='F' and xs[2]>='D' and xs[2]<='F'))){
					cout << '1';
				}else{
					cout << '0';
				}
			}else{
				cout << '0'<<'0';
				return 0;
			}
		}else{
			cout <<'0'<<'0'<<'0';
			return 0;
		}
	}else{
		cout << '0'<<'0'<<'0'<<'0';
		return 0;
	}
	
	
	return 0;
} 
