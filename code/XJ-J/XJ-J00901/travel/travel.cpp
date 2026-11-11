#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	for(int i=1;i<=17;i++){
		cin>>c1>>s1>>c2>>s2;
		if(c1==c2){
			cout<<"1";
		}else{
			cout<<"0";
		}
		if(c1==c2||s1[2]==s2[2]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		if(c1==c2||s1[2]==s2[2]||s1[3]==s2[3]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}