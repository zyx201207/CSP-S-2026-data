#include<bits/stdc++.h>
using namespace std;
int a,c1;
int b,c2;
char c;
char d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c1;
	cin>>c;
	cin>>b>>c2;
	cin>>d;
	if(a==b){
		cout<<"1";
		if(c1==c2){
			cout<<"1";
			if((c<='C'&&d<='C')||((c<='E'&&d<='E')&&(c>='D'&&d>='E'))){
				cout<<"1";
				if(c+1==d||d+1==c){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		} 
		else {
			cout<<"000";
		}
	} 
	else{
		cout<<"0000";
	}
	return 0;
} 
