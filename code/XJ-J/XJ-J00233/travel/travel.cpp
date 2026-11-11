#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int p=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		for(int i=0;i<=1;i++){
			if(b[i]==d[i])p=1;
			else {
				p=0;
				break;
			}
		}
		if(p==1){
			cout<<1;
		}
		else {
			cout<<0<<0<<0;
			return 0; 
			}
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='B'||d[2]=='C'||d[2]=='A'){
				cout<<1;
			}
			else {
				cout<<0<<0;
				return 0;
			}
		}
		else{
			if(d[2]=='F'||d[2]=='D'){
				cout<<1;
			}
			else cout<<0;
		}
		if(abs(b[2]-d[2])==1&&(b[2]!='C'||b[2]!='D')&&(d[2]!='C'||d[2]!='D'))cout<<1;
		else cout<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
