#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<0;
	}
	if(c1[0]==c2[0]&&s1[0]==s2[0]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]=='D'||s2[0]=='F'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
