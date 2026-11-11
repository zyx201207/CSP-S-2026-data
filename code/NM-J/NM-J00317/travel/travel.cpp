#include<bits/stdc++.h>
using namespace std;
char c1[5]={ },s1[5]={ },c2[5]={ },s2[5]={ };
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=4;i++){
    	if(s1[1]==s2[1] && s1[2]==s2[2]){
    		cout<<"1";
		}
		if(s1[3]=='A' && s2[3]=='B'){
			cout<<"1";
		}
		if(s1[3]=='B' && s2[3]=='C'){
			cout<<"1";
		}
		if(s1[3]=='D' && s2[3]=='F'){
			cout<<"1";
		}
		if(s1[3]=='C' && s2[3]=='D'){
			cout<<"0";
		}
		else{
			cout<<"0";
		}
	}
    return 0;
}
