#include<bits/stdc++.h>
using namespace std;
int abs(int a){
	if(a<0)return -a;
	return a;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"1";
					if(abs(s1[2]-s2[2])==1){
						cout<<"1";
					}else cout<<"0";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
