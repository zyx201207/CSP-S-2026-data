#include<bits/stdc++.h>
using namespace std;
int aaa(string a2,string s2){
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		return 1;
	}
	else if((a2[2]=='D'||a2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		return 1;
	}
	else return 0;
}
int bbb(string a2,string s2){
	int q=int(a2[2]);
	int w=int(s2[2]);
	if(q-w==1||q-w==-1){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,a1,a2;
	int f=0;
	cin>>a1>>a2>>s1>>s2;
	if(a1==s1){
		cout<<1;
	}
	else cout<<0;
	if(a1==s1&&a2.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else cout<<0;
	if(a1==s1&&a2.substr(0,2)==s2.substr(0,2)&&aaa(a2,s2)==1){
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(f==1&&bbb(a2,s2)==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
