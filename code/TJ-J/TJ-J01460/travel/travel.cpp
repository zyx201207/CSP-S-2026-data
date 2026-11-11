#include<bits/stdc++.h>
using namespace std;
int cx1 , cx2 ;
int hang1, hang2 ;
char lie1 , lie2 ;
string  zw1 , zw2 ;
void fj(){
	hang1 = (zw1[0] - '0') * 10 + (zw1[1] - '0') ;
	hang2 = (zw2[0] - '0') * 10 + (zw2[1] - '0') ;
	lie1 = zw1[2] ;
	lie2 = zw2[2] ;
}
int main(){
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> cx1 >> zw1 >> cx2 >> zw2 ;
	fj() ;
	if(cx1 != cx2){
		cout << "0000" ;
	}else{
		if(hang1 != hang2){
			cout << "1000" ; 
		}else{
			if(!((lie1 <= 'C' && lie2 <= 'C') || (lie1 >= 'D' && lie2 >= 'D'))){
				cout << "1100" ;
			}else{
				if((lie1 == 'A' && lie2 == 'C') || (lie1 == 'C' && lie2 == 'A')){
					cout << "1110" ;
				}else{
					cout << "1111" ;
				}
			}
		}
	}
	return 0;
}
