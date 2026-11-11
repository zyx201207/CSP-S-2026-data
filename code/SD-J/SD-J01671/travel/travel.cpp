#include <iostream>
#include <cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int n=s1.size();
		char ss1=s1[n-1],ss2=s2[n-1];
		for(int i=0;i<n-1;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<1;
		if((ss1>='A'&&ss1<='C'&&ss2>='D'&&ss2<='E')||(ss2>='A'&&ss2<='C'&&ss1>='D'&&ss1<='E')){
			cout<<"00";
			return 0;
		}
		cout<<1;
		if((ss1=='A'&&ss2=='B')||(ss1=='B'&&ss2=='C')||(ss1=='D'&&ss2=='E')||(ss2=='A'&&ss1=='B')||(ss2=='B'&&ss1=='C')||(ss2=='D'&&ss1=='E')){
			cout<<1;
		}
		else cout<<0;
	}	
	else cout<<"0000";
	return 0;
}
