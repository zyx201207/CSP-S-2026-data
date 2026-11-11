#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2,ans1,ans2,ans3,ans4;
char x1,x2;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['F']=5;
	cin>>c1>>s1>>x1>>c2>>s2>>x2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(mp[x1]<=3&&mp[x2]<=3||mp[x1]>3&&mp[x2]>3){
				cout<<1;
				if(abs(mp[x1]-mp[x2])==1){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}