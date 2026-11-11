#include<bits/stdc++.h>
using namespace std;
string s1,s2,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char c1=s1[2],c2=s2[2];
			if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')){
				cout<<"1";
				if(abs(c1-c2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
