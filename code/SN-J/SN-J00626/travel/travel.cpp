//胡海瑧 西安市铁一中学 SN-J00626 
#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){ cout<<"0000";return 0;}
	else{
		cout<<1;int n=s1.size();
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){ cout<<"11";return 0;}
			else if(s1[2]=='A'){
				if(s2[2]=='B'){cout<<"11";return 0;}
				else if(s2[2]=='C'){cout<<"10";return 0;}
				else{cout<<"00";return 0;}
			}
			else if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C'){cout<<"11";return 0;}
				else{cout<<"00";return 0;}
			}
			else if(s1[2]=='C'){
				if(s2[2]=='B'){cout<<"11";return 0;}
				else if(s2[2]=='A'){cout<<"10";return 0;}
				else{cout<<"00";return 0;}
			}
			else if(s1[2]=='D'){cout<<"00";return 0;}
			else if(s1[2]=='F'){cout<<"00";return 0;}
		}
		else{ cout<<"000";return 0;}
	}
	return 0;
}
