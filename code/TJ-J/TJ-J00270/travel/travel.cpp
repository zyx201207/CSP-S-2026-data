#include<bits/stdc++.h> 
using namespace std;
bool q,q1,q2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string f="F";
	string a="A";
	string b="B";
	string c="C";
	string d="D";
	if(c1[1]==c2[1]){
		cout<<"1";
		q1=true;
	}else{
		cout<<"0";
		q1=false;
	}
	if(s1[1]==s2[1]&&q1){ 
		cout<<"1";
		q=true;
	}else{
		cout<<"0";
		q=false;
	}
	if(s1[2]==f[0]&&s2[2]==d[0]||s1[2]==a[0]&&s2[2]==b[0]||s1[2]==a[0]&&s2[2]==c[0]&&q1&&q){
		cout<<"1";
		q2=true;
	}else{
		q2=false;
		cout<<"0";
	}
	if(q1&&q2&&q){
		if(s1[2]==a[0]&&s2[2]==c[0]){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
