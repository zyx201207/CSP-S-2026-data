#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char s1b,s2b;
string check="ABCDEF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else cout<<1;
	int l1=s1.size(),l2=s2.size();
	s1b=s1[l1-1];
	s2b=s2[l2-1];
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	bool f=0;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1b=='A'||s1b=='B'||s1b=='C'){
				if(s2b=='D'||s2b=='E') cout<<0;
				else{
					cout<<1;
					f=1;	
				}
			}else{
				if(s2b=='A'||s2b=='B'||s2b=='C') cout<<0;
				else{
					cout<<1;
					f=1;
				}
			} 
		}else{
			cout<<0;
		}
	if(f==1){
		if(s1b==s2b+1||s1b==s2b-1) cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
} 
