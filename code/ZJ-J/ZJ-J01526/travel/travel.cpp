#include<bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
	}
	else{
		if(s1[0]==s2[0]&&s2[1]==s1[1]){
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				if(char(s1[2]+1)==s2[2]||char(s2[2]+1)==s1[2]){
					cout<<"1111"<<endl;
				}
				else cout<<"1110"<<endl;
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"1111"<<endl;
			}
			else{
				cout<<"1100"<<endl;
			}
		}
		else{
			cout<<"1000"<<endl;
		}
	}
	//T1 water
	//wlz_can_fly
	//xiang shang mi huo xing wei da shang ZJ
	//luogu UID 1771887 ID chopstick_bus
	return 0;
}