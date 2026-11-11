#include<bits/stdc++.h>
using namespace std ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1 , s1 , c2 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1!=c2){
		cout << "0000" ;
		return 0;
	}
	else{
		cout << 1 ;
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout << "000" ;
			return 0;
		}
		else{
			cout << 1 ;
			int side1=0 , side2=0 ;
			if(s1[2]=='D'||s1[2]=='F')side1++ ;
			if(s2[2]=='D'||s2[2]=='F')side2++ ;
			if(side1!=side2){
				cout << "00" ;
				return 0;
			}
			else{
				cout << 1 ;
				if(abs(s1[2]-s2[2])==1||s2[2]=='D'&&s1[2]=='F'||s1[2]=='D'&&s2[2]=='F'){
					cout << 1 ;
				}
				else{
					cout << 0 ;
				}
			}
		}
	}
	return 0;
}
