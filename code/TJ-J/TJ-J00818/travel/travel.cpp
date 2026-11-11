#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,cnt=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	if(c1==c2){
		cout<<1;
		if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
			cout<<1;
			if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
				if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
					cnt=1;
				}
			}
			if(s1[2]=='D' or s1[2]=='E'){
				if(s2[2]=='D' or s2[2]=='E'){
					cnt=1;
				}
			}
			if(cnt==1){
				cout<<1;	
				if(s1[2]+1==s2[2] or s1[2]-1==s2[2]){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
