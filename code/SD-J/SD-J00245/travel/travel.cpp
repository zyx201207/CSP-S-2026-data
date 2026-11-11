#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	//bool f1=false,f2=false;
	if(ca[0]==cb[0]&&ca[1]==cb[1]){
		cout<<"1";
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			cout<<"1";
			if((sa[2]=='A'||sa[2]=='B'||sa[2]=='C')&&(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')){
				cout<<"1";
				char x=sa[2],y=sb[2];
				if(x=='A'&&y=='B')cout<<"1";
				else if(x=='B'&&(y=='A'||y=='C'))cout<<"1";
				else if(x=='C'&&y=='B')cout<<"1";
				else cout<<"0";
			}
			else if((sa[2]=='D'||sa[2]=='F')&&(sb[2]=='D'||sb[2]=='F')){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
