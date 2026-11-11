#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a=0,b=0;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D'||s1[2]=='F'){
		a++;
	}else b++;
	if(s2[2]=='D'||s2[2]=='F'){
		a++;
	}else b++;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(a==2||b==2){
		cout<<"1";	
		}else cout<<"0";
	}else cout<<"0";
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(a==2){
			cout<<"1";
		}else if(b==2&&s1[2]-s2[2]==1){
			cout<<"1";
		}else if(b==2&&s1[2]-s2[2]==-1){
			cout<<"1";
		}else cout<<"0";
	}else cout<<"0";
	return 0;
}
