#include<bits\stdc++.h>

using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(c1==c3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int w1=(c2[0]-'0')*10+(c2[1]-'0'),w2=(c4[0]-'0')*10+(c4[1]-'0');
	if(w1==w2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(w1==w2){
		if(c2[2]=='F'){
			if(c4[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(c2[2]=='D'){
			if(c4[2]=='F'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if((c2[2]>='A'&&c2[2]<='C')&&(c4[2]>='A'&&c4[2]<='C')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(w1==w2){
		if(c2[2]=='F'){
			if(c4[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(c2[2]=='D'){
			if(c4[2]=='F'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if((c4[2]+1==c2[2]&&c4[2]!='C')||(c2[2]+1==c4[2]&&c2[2]!='C')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
