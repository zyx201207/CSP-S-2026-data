#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool o=0;
	if(c1==c2){
		cout<<1;
		o=0;
	}else{
		cout<<0;
		o=1;
	}
	bool ok=0;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i])ok=1;
	}
	if(!ok&&!o){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'))&&!ok&&!o){
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1[2]+1==s2[2]||s2[2]+1==s1[2])&&!(s1[2]=='C'&&s2[2]=='D')&&!(s2[2]=='C'&&s1[2]=='D')&&!ok&&!o){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
