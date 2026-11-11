#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if((s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'||s1[2]=='F'))){
				cout<<1;
				if((s1[2]==s2[2]+1)||(s2[2]==s1[2]+1)){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
