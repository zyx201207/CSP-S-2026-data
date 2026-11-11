#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int check(string a,string b){
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
		return 1;
	}
	if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
		return 2;
	}
	if((a[2]=='D'||a[2]=='C')||(b[2]=='C'||b[2]=='D')){
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			f=check(s1,s2);
			if(f==0){
				cout<<0<<0;;
			}else if(f==1){
				cout<<1;
				if(((s1[2]=='A'||s1[2]=='C')&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<11;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	
	return 0;
}
