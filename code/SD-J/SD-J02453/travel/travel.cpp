#include<bits/stdc++.h>
using namespace std;
int main (){
//freopen ("travel.in","r",stdin);
//freopen ("travel.out", "w",stdout);
int a, c;
int b, d;
char bl, dl;
cin >> a >> b >> bl >> c >> d >> dl;
if(a==c){
	cout << "1";
	if(b==d){
		cout << "1";
		if( bl=='A'||bl=='B'||bl=='C'&&	 dl=='A'||dl=='B'||dl=='C'  ||   bl=='D'||bl=='F'&&dl=='D'||dl=='F'){
			cout <<"1";
		if(int(bl)+1==int(dl)||int(bl)-1==int(dl)){
			cout << "1";
		}else{
			cout <<"1110";
		}	
		}else{
			cout <<"1100";
		}
	}else{
cout << "1000";
}
	
}else {
	cout << "0000";
}
//fclose(stdin);
//fclose(stdout);
return 0;	
} 
