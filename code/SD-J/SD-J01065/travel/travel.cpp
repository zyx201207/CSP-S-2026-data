#include<bits/stdc++.h>
using namespace std;
int x,y;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if(x==y){
		cout<<1;
		int a=(s1[0]-'0')*10+s1[1]-'0',b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b){
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&s1[2]!='E'&&'D'<=s2[2]&&s2[2]<='F'&&s2[2]!='E')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	return 0;
} 
