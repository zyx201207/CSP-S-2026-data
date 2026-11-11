#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
bool f(string t){
	char c=t[t.size()-1];
	if(c=='A'||c=='B'||c=='C')
		return 1;
	else return 0;
}int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1) {
		cout<<'1';
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			cout<<'1';
			if(f(s2)==f(t2)){
				cout<<'1';
				char c=s2[s2.size()-1],h=t2[t2.size()-1];
				if(c+1==h||c-1==h) cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
