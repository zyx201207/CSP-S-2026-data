#include<bits/stdc++.h> 
using namespace std;
long long c1,s1,c2,s2;
char c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c >> c2 >> s2 >> s;
	if(c1==c2){
		cout << "1";
		if(s1==s2){
			cout << "1";
			if((c<='C'&&s<='C')||(c>='D'&&s>='D')){
				cout << "1";
				if(c+1==s||s+1==c) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
