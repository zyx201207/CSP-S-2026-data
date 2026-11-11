#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1){
		cout<<1;
		int n1=(s2[0]-'0')*10+(s2[1]-'0');
		int n2=(c2[0]-'0')*10+(c2[1]-'0');
		if(n1==n2){
			cout<<1;
			int s=s2[2],c=c2[2];
			if((s=='A'&&c=='B')||(s=='B'&&c=='A')||(s=='A'&&c=='C')||(s=='C'&&c=='A')||(s=='B'&&c=='C')||(s=='C'&&c=='B')||(s=='E'&&c=='D')||(s=='D'&&c=='E')){
				cout<<1;
				if(abs(int(s)-int(c))==1){
					if((s=='C'&&c=='D')||(s=='D'&&c=='C')){
						cout<<0;
					}
					else{
						cout<<1;
					}
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000"; 
	return 0;
}
