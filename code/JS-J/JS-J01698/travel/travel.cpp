#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c1!="16"){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char x=max(s1[2],s2[2]),y=min(s1[2],s2[2]);
			if(x<='C'){
				cout<<"1";
				if(int(x-y)==1)cout<<"1";
				else cout<<"0";
			}
			else if(y>='D'){
				cout<<"1";
				if(int(x-y)==1)cout<<"1";
				else cout<<"0";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
