#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000"<<endl;
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B')cout<<"1111"<<endl;
		else if(s2[2]=='D') cout<<"1100"<<endl;
		else if(s2[2]=='F') cout<<"1100"<<endl;
		else cout<<1110<<endl;
		return 0;
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C')cout<<"1111"<<endl;
		else if(s2[2]=='D') cout<<"1100"<<endl;
		else if(s2[2]=='F') cout<<"1100"<<endl;
		return 0;
	}
	if(s1[2]=='C'){
		if(s2[2]=='B')cout<<"1111"<<endl;
		else if(s2[2]=='D') cout<<"1100"<<endl;
		else if(s2[2]=='F') cout<<"1100"<<endl;
		else cout<<"1110"<<endl;
		return 0;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F')cout<<"1111"<<endl;
		else if(s2[2]=='C') cout<<"1100"<<endl;
		else if(s2[2]=='B') cout<<"1100"<<endl;
		else if(s2[2]=='A') cout<<"1100"<<endl;
		return 0;
	}
	if(s1[2]=='F'){
		if(s2[2]=='D')cout<<"1111"<<endl;
		else if(s2[2]=='C') cout<<"1100"<<endl;
		else if(s2[2]=='B') cout<<"1100"<<endl;
		else if(s2[2]=='A') cout<<"1100"<<endl;
		return 0;
	}
	return 0;
}