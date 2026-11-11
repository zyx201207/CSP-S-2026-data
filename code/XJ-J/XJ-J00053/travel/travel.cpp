#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,h1,h2; 
 	cin>>c1>>s1>>c2>>s2;
 	h1=s1[0];
 	h1+=s1[1];
 	h2=s2[0];
 	h2+=s2[1];
 	s1=s1[2];
 	s2=s2[2];
 	if(c1==c2){
 		cout<<1;
 		if(h1==h2){
 			cout<<1;
 			if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="C")||(s1=="A"&&s2=="C")||(s1=="D"&&s2=="E")||(s2=="A"&&s1=="B")||(s2=="B"&&s1=="C")||(s2=="A"&&s1=="C")||(s2=="D"&&s1=="E")){
 				cout<<1;
 				if(int(s2[0])-int(s1[0])==1||int(s2[0])-int(s1[0])==-1){
 					cout<<1;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
