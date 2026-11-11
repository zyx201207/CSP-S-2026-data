#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,c3,c4;
	
	cin >> c1 >> c2 >> c3 >> c4;
	
	 
	if(c1 == c3){
		cout << true;

	
		if(c2[0] == c4[0] && c2[1] == c4[1]){
			cout << true;
		}
		
		else cout << false;
		
	
		if( c2[2]==65 && c4[2]==68 ){
			cout << false;
		}
			else if(c2[2]==66 && c4[2]==68 ){
			cout << false;
		}
		else if(c2[2]==67 && c4[2]==68 ){
			cout << false;
		}
		else if(c2[2]==65 && c4[2]==70){
			cout << false;
		} 
		else if(c2[2]==66 && c4[2]==70){
			cout << false;
		}
		else if(c2[2]==67 && c4[2]==70){
			cout << false;
		}
	
		else cout << true;
		
	
		if(c2[2] == 67 && c4[2] == 68){
			cout << false;
		}
		else if(c2[0] == c4[0] && c2[1] == c4[1]  &&  c2[2] + 1 == c4[2] || c2[2] + 1 == c4[2] + 1){
			cout << true;
		}
		
	
		}
	if(c1 != c3){
		for(int i=0;i<=3;i++) cout << false;
		
}
}
