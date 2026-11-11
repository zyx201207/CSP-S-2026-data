#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		string a1,a2;
		a1+=s1[0];
		a1+=s1[1];
		a2+=s2[0];
		a2+=s2[1];
		//cout<<a1<<" "<<a2<<" ";
		if(a1==a2){
			cout<<1;
			if((((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
			||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))&&s1[2]!=s2[2]){
				cout<<1;
				if(abs(s1[2]-s2[2])==1||((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')) ) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}
		else cout<<"000";
		
	}
	return 0;
}
