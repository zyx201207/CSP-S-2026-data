#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	bool a,b;
	int s1[2]={x,a},s2[2]={y,b};
	string c1,c2;
	cin>>c1>>a>>c2>>b;
	if(c1=="01"||c2=="01"||c1=="16"||c2=="16"){
		cout<<'0';
	}else{
		cout<<'1';
	}
	if(s1[x]==s2[y]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(s1[x]==s2[y]&&s1[a]=='A'&&s2[b]=='B'||s1[x]==s2[y]&&s1[a]=='B'&&s2[b]=='C'||s1[x]==s2[y]&&s1[a]=='D'&&s2[b]=='E'||s1[x]==s2[y]&&s1[a]=='B'&&s2[b]=='A'||s1[x]==s2[y]&&s1[a]=='C'&&s2[b]=='B'||s1[x]==s2[y]&&s1[a]=='E'&&s2[b]=='D'){
		cout<<'0';
	}else{
		cout<<'1';
	}
	if(s1[x]==s2[y]&&s1[a]=='A'&&s2[b]=='B'||s1[x]==s2[y]&&s1[a]=='B'&&s2[b]=='C'||s1[x]==s2[y]&&s1[a]=='A'&&s2[b]=='C'||s1[x]==s2[y]&&s1[a]=='D'&&s2[b]=='E'||s1[x]==s2[y]&&s1[a]=='B'&&s2[b]=='A'||s1[x]==s2[y]&&s1[a]=='C'&&s2[b]=='B'||s1[x]==s2[y]&&s1[a]=='C'&&s2[b]=='A'||s1[x]==s2[y]&&s1[a]=='E'&&s2[b]=='D'){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
