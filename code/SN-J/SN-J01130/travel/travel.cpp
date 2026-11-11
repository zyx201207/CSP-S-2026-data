#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char m,n;
	cin>>a>>b>>m>>c>>d>>n;
    if(a==c){
    	cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b==d){
		cout<<"1";
		if((m=='A'&&(n=='B'||n=='c'))||(m=='A'&&(n=='B'||n=='C'))||(m=='D'&&n=='F')||(m=='F'&&n=='D')){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	if((m=='A'&&(n=='B'||n=='c'))||(m=='A'&&(n=='B'||n=='C'))||(m=='D'&&n=='F')||(m=='F'&&n=='D')){
	    	cout<<"1";
		}
	else{
			cout<<"0";
	    }
	}
	else{
		cout<<"000";
	}
}
