#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	char t1,t2;
	for(int i=0;i<s1.size();i++){
		if(isalpha(s1[i])){
			t1=s1[i];
			s1.erase(i);
		}
	}
	for(int i=0;i<s2.size();i++){
		if(isalpha(s2[i])){
			t2=s2[i];
			s2.erase(i);
		}
	}
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C'))||((t1=='D'||t1=='E')&&(t2=='D'||t2=='E'))){
		cout<<1;
		if(abs(int(t1)-int(t2))==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0<<0;
	}
	return 0;
}
