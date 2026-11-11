#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	map<char,int>a;
	a['A']=1;
	a['B']=1;
	a['C']=1;
	a['D']=2;
	a['F']=2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			if(a[s1[2]]==a[s2[2]]){
				cout<<'1';
				if(s1[2]=='A'){
					if(s2[2]=='B')cout<<'1';
					else cout<<'0';
				}else if(s1[2]=='B'){
					if(s2[2]=='A'||s2[2]=='C')cout<<'1';
					else cout<<'0';
				}else if(s1[2]=='C'){
					if(s2[2]=='B')cout<<'1';
					else cout<<'0';
				}else if(s1[2]=='D'){
					if(s2[2]=='F')cout<<'1';
					else cout<<'0';
				}else{
					if(s2[2]=='D')cout<<'1';
					else cout<<'0';
					
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}

