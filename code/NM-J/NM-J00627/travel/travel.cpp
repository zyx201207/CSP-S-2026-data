#include <bits/stdc++.h>
using namespace std;
int main(){
   	freopen("travel.in","r",stdin);
   	freopen("travel.out","w",stdout);
    string a,b,a1,b1;
    cin >> a >> a1 >> b>> b1;
    if( a == b ){
        if ( a1[0] == b1[0] && a1[1] == b1[1] ) {

			if(a1[2]=='A'){
				if(b1[2]=='B'||b1[2]=='C'){
					if(a1[2]-1==b1[2]||a1[2]+1==b1[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				}else{
					cout<<"1100";
				}
			}else if(a1[2]=='B'){
				if(b1[2]=='A'||b1[2]=='C'){
					if(a1[2]-1==b1[2]||a1[2]+1==b1[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				}else{
					cout<<"1100";
				}
			}else if(a1[2]=='C'){
				if(b1[2]=='A'||b1[2]=='B'){
					if(a1[2]-1==b1[2]||a1[2]+1==b1[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				}else{
					cout<<"1100";
				}
			}else if(a1[2]=='D'){
				if(b1[2]=='F'){
					if(a1[2]-1==b1[2]||a1[2]+1==b1[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				}else{
					cout<<"1100";
				}
			}else if(a1[2]=='F'){
				if(b1[2]=='D'){
					if(a1[2]-1==b1[2]||a1[2]+1==b1[2]){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
				}else{
					cout<<"1100";
				}
			}else{
				cout<<"1100" ;
			}
    	}else{
       		cout << "1000";
    	}
	}else{
		cout << "0000";
	}
    return 0;
}
