#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<0<<0<<0<<endl;
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='C'){
			cout<<1<<0<<endl;
			return 0;
		}
		else if(s2[2]=='B'){
			cout<<1<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<0<<endl;
			return 0;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='C'||s2[2]=='A'){
			cout<<1<<1<<endl;
			return 0;
		}
	}
	if(s1[2]=='C'){
		if(s2[2]=='A'){
			cout<<1<<0<<endl;
			return 0;
		}
		else if(s2[2]=='B'){
			cout<<1<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<0<<endl;
			return 0;
		}
	}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<1<<1<<endl;
		return 0;
	}
	else{
		cout<<0<<0<<endl;
		return 0;
	}
	return 0;
} 
