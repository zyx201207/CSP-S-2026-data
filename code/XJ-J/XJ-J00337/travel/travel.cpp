#include<bits/stdc++.h>
using namespace std;
int c,s;
string cp,sp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c>>cp>>s>>sp;
	if(c==s){
		cout<<'1';
		if((cp[0]-'0')*10+cp[1]-'0'==(sp[0]-'0')*10+sp[1]-'0'){
			cout<<'1';
			if(cp[2]-'A'<3 && sp[2]-'A'<3){
				cout<<'1';
				if(cp[2]-'A'+sp[2]-'A'!=2){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(cp[2]-'A'>=3 && sp[2]-'A'>=3){
				cout<<"11";
			}else{
				cout<<"00";
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