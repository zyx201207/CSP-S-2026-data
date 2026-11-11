#include<bits/stdc++.h>
using namespace std;
long long a,b;
string s1,s2;
int main(){
	fropen("travel.in","r",stdin);
	fropen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(('A'==s1[2]||'B'==s1[2]||'C'==s1[2])&&('A'==s2[2]||'B'==s2[2]||'C'==s2[2])){
				cout<<1;
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(('D'==s1[3]&&'F'==s2[3])||('D'==s2[3]&&'F'==s2[3])){
				cout<<11;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}