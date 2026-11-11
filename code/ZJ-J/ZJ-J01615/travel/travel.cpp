#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	if((b[0]+b[1])==(d[0]+d[1]))cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'){
		if(d[2]=='B')cout<<"11";
		else if(d[2]=='C')cout<<"10";
		else if(d[2]=='D')cout<<"00";
		else if(d[2]=='E')cout<<"00";
	}
	if(b[2]=='B'){
		if(d[2]=='A')cout<<"11";
		else if(d[2]=='C')cout<<"11";
		else if(d[2]=='D')cout<<"00";
		else if(d[2]=='E')cout<<"00";
	}
	if(b[2]=='C'){
		if(d[2]=='A')cout<<"10";
		else if(d[2]=='B')cout<<"11";
		else if(d[2]=='D')cout<<"00";
		else if(d[2]=='E')cout<<"00";
	}
	if(b[2]=='D'){
		if(d[2]=='A')cout<<"00";
		else if(d[2]=='B')cout<<"00";
		else if(d[2]=='C')cout<<"00";
		else if(d[2]=='E')cout<<"10";
	}
	if(b[2]=='E'){
		if(d[2]=='A')cout<<"00";
		else if(d[2]=='B')cout<<"00";
		else if(d[2]=='C')cout<<"00";
		else if(d[2]=='D')cout<<"10";
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
