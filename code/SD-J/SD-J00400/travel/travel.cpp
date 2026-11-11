#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
char zf[3],zfzf[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		for(int i=0;i<s.length();i++){
			zf[i]=s[i];
			zfzf[i]=ss[i];
		}
		if(zf[1]==zfzf[1]&&zf[0]==zfzf[0]){
			cout<<"1";
			if(zf[2]=='A'&&zfzf[2]=='B'||zf[2]=='A'&&zfzf[2]=='C'||zf[2]=='B'&&zfzf[2]=='A'||zf[2]=='B'&&zfzf[2]=='C'||zf[2]=='C'&&zfzf[2]=='A'||zf[2]=='C'&&zfzf[2]=='B'||zf[2]=='D'&&zfzf[2]=='F'||zf[2]=='F'&&zfzf[2]=='D'){
				cout<<"1"<<(zf[2]=='A'&&zfzf[2]=='B'||zf[2]=='B'&&zfzf[2]=='A'||zf[2]=='B'&&zfzf[2]=='C'||zf[2]=='C'&&zfzf[2]=='B'||zf[2]=='D'&&zfzf[2]=='F'||zf[2]=='F'&&zfzf[2]=='D')?"1":"0";
			}
			else cout<<"00";
			return 0;
		}
		else{
			cout<<"000";
			return 0;
		}
		
	}
	return 0;
}
