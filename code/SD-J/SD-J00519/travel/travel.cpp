#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	bool f=0,ff=0,fff=0,ffff=0;
	if(c==cc){
		f=1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			ff=1;
			if(((s[2]>='A'&&s[2]<='C')&&(ss[2]>='A'&&ss[2]<='C'))||((s[2]>='D'&&s[2]<='F')&&(ss[2]>='D'&&ss[2]<='F'))){
				fff=1;
				if(s[2]=='D'||s[2]=='F'){
					ffff=1;
					cout<<f<<ff<<fff<<ffff;
					return 0;
				}else if(s[2]=='B'||ss[2]=='B'){
					ffff=1;
					cout<<f<<ff<<fff<<ffff;
					return 0;
				}else if((s[2]=='A'&&ss[2]!='C')||(s[2]=='C'&&ss[2]!='A')){
					ffff=1;
					cout<<f<<ff<<fff<<ffff;
					return 0;
				}else{
					cout<<f<<ff<<fff<<ffff;
					return 0;
				}
			}else{
				cout<<f<<ff<<fff<<ffff;
				return 0;
			}
		}else{
			cout<<f<<ff<<fff<<ffff;
			return 0;
		}
	}else{
		cout<<f<<ff<<fff<<ffff;
		return 0;
	}
	return 0; 
} 
