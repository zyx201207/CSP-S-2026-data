#include<bits/stdc++.h>
#define open(x) string fn=x;freopen((fn+".in").c_str(),"r",stdin);freopen((fn+".out").c_str(),"w",stdout);
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(s) s.begin(),s.end()
#define endl '\n'
using namespace std;
using ll=long long;
 
signed main(){
	open("travel");
	io;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ss1=s1,ss2=s2;
	ss1[2]='\0';
	ss2[2]='\0';
	if(c1==c2){
		if(ss1==ss2){
			if(((s1[2]>='A'&&s1[2]<='C')&&s2[2]>='A'&&s2[2]<='C')||((s1[2]=='D'||s1[2]=='F')&&s2[2]=='D'||s2[2]=='F')){
				if((((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))||((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')))){
					cout<<"1111"<<endl;
				}
				else{
					cout<<"1110"<<endl;
				}
			}
			else{
				cout<<"1100"<<endl;
			}
		}
		else{
			cout<<"1000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
}

