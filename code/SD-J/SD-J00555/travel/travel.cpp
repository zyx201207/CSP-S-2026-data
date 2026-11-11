#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	bool flag=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){//同行 
			cout<<"1";
			if( (s1[2]<'D' && s2[2]<'D') || (s1[2]>'C' && s2[2]>'C') ){//过道同侧 
				cout<<"1";
				flag=1;
			}
			else
				cout<<"0";
		}
		else{
			cout<<"00";
		}
		
		//问题4 
		if(flag==1){//过道 
			if( (s1[2]+1==s2[2]) || (s1[2]-1==s2[2]) || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F') ){//同行
				if(s1[0]==s2[0] && s1[1]==s2[1])
					cout<<"1";
				else
					cout<<"0";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"0";
		}
		
	}
	else{
		cout<<"0000";
	}
	return 0;
}
/*
02 01F 02 01D
02 01F 02 02D
02 01F 02 01A
02 01F 03 01D
02 01C 01 01D
*/
