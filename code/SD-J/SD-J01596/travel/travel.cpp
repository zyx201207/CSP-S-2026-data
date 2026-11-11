#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		string s="",t="";
		for(int i=0;i<=1;i++){
			s+=b[i];
			t+=d[i];
		}
		if(s==t){
			cout<<1;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='C'||d[2]=='B'||d[2]=='A'){
					cout<<1;
					if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='C'||d[2]=='A'))||(b[2]=='C'&&d[2]=='B')){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}else if(b[2]=='D'||b[2]=='F'){
				if(d[2]=='D'||d[2]=='F'){
					cout<<1;
					if((b[2]=='F'||d[2]=='D')||(b[2]=='D'&&d[2]=='F')){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
