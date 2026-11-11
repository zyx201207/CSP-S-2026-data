#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,m,n,mm,nn;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>x>>s1>>y>>s2;
	a=int(s1[0]-'0')*10+int(s1[1]-'0');
	b=int(s2[0]-'0')*10+int(s2[1]-'0');
	mm=int(s1[2]-'A')+1;
	nn=int(s2[2]-'A')+1;
	m=min(mm,nn);
	n=max(mm,nn);
	if(n==6)n=5;
	if(x!=y){
		cout<<"0000";
	}
	else if(a!=b){
		cout<<"1000";
	}
	else if(m<=3&&n>3){
		cout<<"1100";
	}
	else if(n==3&&m==2){
		cout<<"1111";
	}
	else if(n==2&&m==1){
		cout<<"1111";
	}
	else if(n==5&&m==4){
		cout<<"1111";
	}
	else {
		cout<<"1110";
	}
	return 0;
}
