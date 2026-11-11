#include<bits/stdc++.h>

using namespace std;

int cr,cx,hr,hx,ans[6];
string sr,sx;
char fr,fx;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cr>>sr>>cx>>sx;
	
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	ans[1]=1;
	if(sr[0]=='0') hr=sr[1]-'0';
	else hr=(sr[0]-'0')*10+(sr[1]-'0');
	if(sx[0]=='0') hx=sx[1]-'0';
	else hx=(sx[0]-'0')*10+(sx[1]-'0');
	
	fr=sr[2],fx=sx[2];
	if(hr==hx){
		ans[2]=1;
		if(fr>='A'&&fr<='C'&&fx>='A'&&fx<='C'||fr>='D'&&fr<='F'&&fx>='D'&&fx<='F'){
			ans[3]=1;
		}
		if(fr=='A'&&fx=='B'||fr=='B'&&fx=='C'||fr=='D'&&fx=='F') ans[4]=1;
		else{
			swap(fr,fx);
			if(fr=='A'&&fx=='B'||fr=='B'&&fx=='C'||fr=='D'&&fx=='F') ans[4]=1;
		}
	}
	for(int i=1;i<=4;i++) cout<<ans[i];
	
	
	return 0;
} 
