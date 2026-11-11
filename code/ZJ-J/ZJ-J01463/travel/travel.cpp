#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int n=c1[0]-67;
	n=n*10+(c1[1]-67);
	int m=s1[0]-67;
	m=m*10+(s1[1]-67);
	if(n==m){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	int x=c2[0]-67;
	x=x*10+c2[1];
	int y=s2[0]-67;
	y=y*10+s2[1];
	if(x==y){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<'1';
		if(abs(c2[2]-s2[2])==1){
			cout<<'1';
		}
		else{
			cout<<'0';
		}
	}
	else if((c2[2]=='D'||c2[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
}
