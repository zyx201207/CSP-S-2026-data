#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[0]>>c1[1]>>s1[0]>>s1[1]>>s1[2]>>c2[0]>>c2[1]>>s2[0]>>s2[1]>>s2[2];
	e=s1[2]-'A';
	f=s2[2]-'A';
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(e<=2&&f<=2){
				cout<<"1";
				if(e+1==f||f+1==e){
					cout<<"1"<<endl;
				}else{
					cout<<"0"<<endl;
				}
			}else if(e>=3&&f>=3){
				cout<<"11"<<endl;
			}else{
				cout<<"00"<<endl;
			}
		}else{
			cout<<"000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
