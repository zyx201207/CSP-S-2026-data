#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
			if((a==1 && b==2) || (a==1 && b==3) || (a==2 && b==1) || (a==2 && b==3) || (a==3 && b==1) || (a==3 && b==2) || (a==4 && b==5) || (a==5 && b==4)){
				cout<<"1";
				if((a==1 && b==2) || (a==2 && b==1) || (a==2 && b==3) || (a==3 && b==2) || (a==4 && b==5) || (a==5 && b==4)){
					cout<<"1";
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
