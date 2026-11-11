#include<bits/stdc++.h>
using namespace std;
char cl2,cl4;
int c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>cl2>>c3>>c4>>cl4;
	if(cl2=='F')cl4='E';
	if(cl4=='F')cl4='E';
	int x=(cl4-'A')-(cl2-'A');
	
	if(c1==c3){
		cout<<"1";
		if(c2==c4){
			cout<<"1";
			if(cl2=='C'&&cl4=='D'){
				cout<<"00";
				return 0;
			}
			else if(cl4=='C'&&cl2=='D'){
				cout<<"00";
				return 0;
			}
			else{
				cout<<1;
				if((x==1)||(x==-1))cout<<"1";
				else cout<<"0";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
