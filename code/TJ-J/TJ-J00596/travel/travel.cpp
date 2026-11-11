#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
				cout<<"11";
			}else{
				char a1=min(s1[2],s2[2]);
				char a2=max(s1[2],s2[2]);
				if((a1>='A'&&a1<='C')&&(a2>='A'&&a2<='C')){
					cout<<"1";
					if(a2-a1==1)cout<<"1";
					else cout<<"0";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
