#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}else{
		string p;
		p+=s1[0];
		p+=s1[1];
		
		string p1;
		p1+=s2[0];
		p1+=s2[1];
		
		if(p!=p1){
			cout << "1000";
			return 0;
		}else{
			char a=s1[2];
			char b=s2[2];
			if( (a=='A'||a=='B'||a=='C')&&(b=='D'||b=='F') || (b=='A'||b=='B'||b=='C')&&(a=='D'||a=='F')){
				cout << "1100";
				return 0;
			}else{
				if((a == 'A'&& b=='C')||(b == 'A'&&a == 'C')){
					cout << "1110";
					return 0;
				}else{
					cout << "1111";
					return 0;
				}
			}
		}
	}
	return 0;
}
