#include<bits/stdc++.h>
using namespace std;
int a,b;
int c,d;
string n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>n;
 	cin>>b>>d>>m;
	if(a==b){
		cout<<"1";
		if(c==d){
			cout<<"1";
			if(n=="A" && m=="B"){
				cout <<"11";
			}else if(n=="A" && m=="C"){
				cout <<"10";
			}else if(n=="B" && m=="A"){
				cout <<"11";
			}else if(n=="B" && m=="C"){
					cout <<"11";
			}else if(n=="C" && m=="A"){
				cout <<"10";
			}else if(n=="C" && m=="B"){
				cout <<"11";
			}else if(n=="D" && m=="F"){
				cout <<"11";
			}else if(n=="F" && m=="D"){
				cout <<"11";
			}else if(n=="C" && m=="D"){
				cout <<"00";
			}else if(n=="D" && m=="C"){
				cout <<"00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
