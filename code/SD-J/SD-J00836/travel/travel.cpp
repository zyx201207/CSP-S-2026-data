#include<bits/stdc++.h>
using namespace std;

int num(char c){
	if(c=='A'||c=='B'||c=='C') return 1;
	return 2;
}
string ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string s1,s2,s3,s4;cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			if(num(s2[2])==num(s4[2])){
				cout<<1;
				ss="0";ss+=s2[2];ss+=s4[2];
//				cout<<(ss[1]=='A');
				if(ss[1]>ss[2]) {swap(ss[1],ss[2]);}
				if((ss[1]=='A'&&ss[2]=='B')||(ss[1]=='B'&&ss[2]=='C')||(ss[1]=='D'&&ss[2]=='F')) cout<<1;
				else cout<<0;
			}else {cout<<"00";}
		}else {cout<<"000";}
	}else {cout<<"0000";}
	
	return 0;
}

