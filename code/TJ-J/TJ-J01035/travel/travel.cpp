#include<bits/stdc++.h>
using namespace std;
string c,c2,s,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>c2>>s>>s2;
	if(c[0]-'0'==s[0]-'0' and c[1]-'0'==s[1]-'0'){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}if(s2[0]-'0'==c2[0]-'0' and s2[1]-'0'==c2[1]-'0'){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}if(s2[0]-'0'==c2[0]-'0' and s2[1]-'0'==c2[1]-'0'){
		bool flag=0;
		if(c2[2]=='A' or c2[2]=='B' or c2[2]=='C'){
			if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
				cout<<1;
				flag=1;
			}
		}else{
			cout<<0<<0;
			return 0;
		}
		if(flag==0){
			if(c2[2]=='D' or c2[2]=='E'){
				if(s2[2]=='D' or s2[2]=='E'){
					cout<<1;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}
	}else{
		cout<<0<<0;
		return 0;
	}if(c2[2]=='A' and s2[2]=='B' or c2[2]=='B' and s2[2]=='A' or c2[2]=='B' and s2[2]=='C' or c2[2]=='C' and s2[2]=='B' or c2[2]=='D' and s2[2]=='E' or c2[2]=='E' and s2[2]=='D'){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
} 
