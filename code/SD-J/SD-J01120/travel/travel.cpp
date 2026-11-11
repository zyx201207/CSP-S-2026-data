#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
string c,cc,ccc,cccc,s;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> cc >> ccc >> cccc;
	if(c==ccc){
		s+='1'; 
		if(cc[0]==cccc[0]&&cc[1]==cccc[1]) {
			s+='1';
			if((cc[2]>'C'&&cccc[2]>'C')||(cc[2]<='C'&&cccc[2]<='C')){
				s+='1';
				if(abs((int)cc[2]-cccc[2])==1||((cc[2]=='D'&&cccc[2]=='F')||(cc[2]=='F'&&cccc[2]=='D'))){
					s+='1';
				}
				else s+='0';
			}
			else s+="00";
		}
		else s+="000";
	}
	else{
		s+="0000";
	}
	cout << s;
	return 0;
}

