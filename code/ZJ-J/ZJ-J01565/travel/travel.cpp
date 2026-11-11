#include<bits/stdc++.h>
using namespace std;
string r1,r2,s1,s2;
int ans=0;
void asd(){
	for(int i=0;i<2;i++){
		if(r2[i]==s2[i]){
			ans++;
		}
	}
}
void sdf(){
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			ans=1;
			return ;
		}
	}
	if(r2[2]=='D'||r2[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			ans=1;
			return ;
		}
	}
}
bool dfg(){
	if(r2[2]=='A'&&s2[2]=='B'){
		return 1;
	}
	if(r2[2]=='B'&&s2[2]=='A'){
		return 1;
	}
	if(r2[2]=='B'&&s2[2]=='C'){
		return 1;
	}
	if(r2[2]=='C'&&s2[2]=='B'){
		return 1;
	}
	if(r2[2]=='D'&&s2[2]=='F'){
		return 1;
	}
	if(r2[2]=='F'&&s2[2]=='D'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>s1>>s2;
	if(r1==s1){
		cout<<"1";
	}
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	asd();
	if(ans==2){
		cout<<"1";
	}
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	ans=0;
	sdf();
	if(ans==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		cout<<"0";
		return 0;
	}
	ans=0;
	if(dfg()){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}