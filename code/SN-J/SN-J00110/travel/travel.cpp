#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cnt+=1000;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<cnt;
			return 0;
		}
	}
	cnt+=100;
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
    	cnt+=10; 
	}else{
		cout<<cnt;
		return 0;
	}
	int x=s1[2]-'0';
	int y=s2[2]-'0';
	if(abs(x-y)==1){
		cnt+=1;
	}else{
		cout<<cnt;
		return 0;
	}
	cout<<cnt;
	return 0;
} 
