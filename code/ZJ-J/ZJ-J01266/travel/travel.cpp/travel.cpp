#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<s1.size();i++){
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<1;
			}else{
				cout<<"000";
				break;
			}
			if(s1[2]>='A'&&s1[2]<='C'){
				if(s2[2]>='A'&&s2[2]<='C'){
					if(s1[2]=='A'&&s1[2]=='B'){
						cout<<11;
						break;
					}
					else if((s1[2]=='B'&&s1[2]=='C')||(s1[2]=='B'&&s1[2]=='A')){
						cout<<11;
						break;
					}
					else if(s1[2]=='C'&&s1[2]=='B'){
						cout<<11;
						break;
					}
					else{
						cout<<10;
						break;
					}
				}else{
					cout<<"00";
					break;
				}
				
			}
			if(s1[2]=='D'||s2[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<11;
					break;
				}
				else{
					cout<<"00";
					break;
				}
			}
		}
	}else{
		cout<<"0000";
	}
	return 0;
}