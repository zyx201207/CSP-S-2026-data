#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
//	getchar();
//	cout<<c1<<endl<<s1<<endl<<c2<<endl<<s2;
	if(c1==c2){
		cout<<1;
		bool b=1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				b=0;
				break;
			}
		}
		if(b){
			cout<<1;
			if(s1[2]=='D'&&s2[2]!='F') cout<<0<<0;
			else if(s1[2]=='F'&&s2[2]!='D') cout<<0<<0;
			else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='F'||s2[2]=='D')) cout<<0<<0;
			else{
				cout<<1;
				if(s1[2]=='D'&&s2[2]=='F') cout<<1;
				else if(s1[2]=='F'&&s2[2]=='D') cout<<1;
				else if(s1[2]=='A'&&s2[2]=='B') cout<<1;
				else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
				else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
				else cout<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	
	
	return 0;
}
//-O2 -std=c++14 -static
 
