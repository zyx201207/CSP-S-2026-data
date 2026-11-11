#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			if(s2[2]=='F')s2[2]='E';
			if(c2[2]=='F')s2[2]='E';
			int a=abs(s2[2]-c2[2]);
			if(a==1&&!((s2[2]=='D'&&c2[2]=='C')||(s2[2]=='C'&&c2[2]=='D'))){
				cout<<"1111";
			}else{
				bool f=0;
				if(s2[2]=='D'&&c2[2]=='C'){
					cout<<"1100";
				}else if(s2[2]=='D'&&c2[2]=='B'){
					cout<<"1100";
				}else if(s2[2]=='D'&&c2[2]=='A'){
					cout<<"1100";
				}else if(s2[2]=='E'&&c2[2]=='C'){
					cout<<"1100";
				}else if(s2[2]=='E'&&c2[2]=='B'){
					cout<<"1100";
				}else if(s2[2]=='E'&&c2[2]=='C'){
					cout<<"1100";
				}else{
					cout<<"1110";
				}
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
    return 0;
}

