#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;	
	}
	int flag=0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag=1;
		}
	}
	if(!flag)cout<<"1";
	else{
		cout<<"000";
		return 0;	
	}
	char n=s1[2];
	char m=s2[2];
	if((n=='A'||n=='B'||n=='C')&&(m=='A'||m=='B'||m=='C'))cout<<"1";
	else if((n=='D'||n=='F')&&(m=='D'||m=='F'))cout<<"1";
	else cout<<"0";
	if((n=='C'&&m=='D')||(n=='D'&&m=='C'))cout<<"0";
	else if(abs(n-m)!=1)cout<<"0";
	else cout<<"1";
	return 0;
}
