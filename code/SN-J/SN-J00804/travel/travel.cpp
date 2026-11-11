//SN-J00804 张馨月 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<1;
		if((s1[0]!=s2[0])||(s1[1]!=s2[1])){
			cout<<"000";
		}
		else{
			cout<<1;
			if(s1[2]=='A'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"00";
				}
				else{
					cout<<1;
					if(s2[2]=='B'){
						cout<<1;
					}
					else cout<<0;
				}
			}
			else if(s1[2]=='B'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"00";
				}
				else{
					cout<<11;
				}
			}
			else if(s1[2]=='C'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"00";
				}
				else{
					cout<<1;
					if(s2[2]=='B'){
						cout<<1;
					}
					else cout<<0;
				}
			}
			else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"00";
				}
				else{
					cout<<11;
				}
			}
		}
	}
	
	
	return 0;
}
