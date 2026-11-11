#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=1;
int x;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	x=s1.size()-1;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i])flag=0;
	}
	if(!flag){
		cout<<"0000";
		return 0;
	}
	flag=1;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i])flag=0;
	}
	if(!flag){
		cout<<"1000";
		return 0;
	}
	if(char(s1[x])<='C'&&char(s2[x])>='D'||char(s2[x])<='C'&&char(s1[x])>='D'){
		cout<<"1100";
		return 0;
	}
	if(int(s1[x])==int(s2[x])+1||int(s1[x])==int(s2[x])-1||s1[x]=='D'&&s2[x]=='F'||s2[x]=='D'&&s1[x]=='F'){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
