#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,mx,mn;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	c=(s1[0]-'0')*10+(s1[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	mx=max(s1[2]-'A'+1,s2[2]-'A'+1);
	mn=min(s1[2]-'A'+1,s2[2]-'A'+1);
	if(mx==6) mx--;
	if(a==b) {
		cout<<1;
		if(c==d){
			cout<<1;
			if(mn<4 and mx<4){
				if(mx-mn==1){
					cout<<"11";
				}
				else cout<<"10";
			}
			else if(mn>=4 and mx>=4){
				cout<<"11";
			}
			else cout<<"00";
		} 
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
