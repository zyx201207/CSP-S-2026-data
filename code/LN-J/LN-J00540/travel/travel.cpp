#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string s3=s1.substr(0,2),s4=s2.substr(0,2);
	if(c1==c2){
		cout<<1;
		if(s3==s4){
			cout<<1;
			char a=s1[2],b=s2[2];
			bool a1=false,b1=false;
			if(a=='A'||a=='B'||a=='C')a1=true;
			if(b=='A'||b=='B'||b=='C')b1=true;
			if(a1==b1){
				cout<<1;
				if(a+1==b||a-1==b)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	cout<<'\n';
	return 0;
}
