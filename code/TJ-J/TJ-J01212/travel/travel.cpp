#include<bits/stdc++.h> 
using namespace std;
int temp=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	//deviding line
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	//deviding line
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]==s2[i]){
			temp+=1;
		}
	}
	if(temp==2 && c1==c2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	//deviding line
	if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='F' || s2[2]=='D') && temp==2 && c1==c2){
		cout<<'1';
	}
	else if((s1[2]!='D' && s1[2]!='F') && (s2[2]!='F' && s2[2]!='D') && temp==2 && c1==c2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	//deviding line
	if((s1[2]=='A' || s1[2]=='B') && (s2[2]=='B' || s2[2]=='A') && temp==2 && c1==c2){
		cout<<'1';
	}
	else if((s1[2]=='C' || s1[2]=='B') && (s2[2]=='B' || s2[2]=='C') && temp==2 && c1==c2){
		cout<<'1';
	}
	else if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='F' || s2[2]=='D') && temp==2 && c1==c2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
