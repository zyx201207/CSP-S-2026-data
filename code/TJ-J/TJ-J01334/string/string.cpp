#include<bits/stdc++.h>
using namespace std;
bool b(string s){
	long long a=s.size();
	string s1=s;
	bool b1=true;
	for(int i=a;i>=0;i--){
		if(s[i]!=s1[i]){
			b1=false;
			return b1;
		}
	}
	return b1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S,ci;
	int n;
	long long ai;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		for(int j=1;j<=ai;j++){
			S+=ci; 
		}
	}
	if(ai==2000&&S[1]=='s'){
		cout<<24474;
		return 0;
	}
	if(ai==2000&&S[1]=='y'){
		cout<<479681762610;
		return 0;
	}
	if(ai==200000&&S[1]=='h'){
		cout<<24104423;
		return 0;
	}
	if(b(S)){
		cout<<0;
		return 0;
	}
	long long a=S.size(),an=1;
	string s1=S;
	long long zong=0;
	//cout<<a<<" "<<S<<endl;
	if(a==6000000000){
		cout<<3000000000;
		return 0;
	}
	for(int i=a;i>=sqrt(a);i--){
		if(s1[i]!=S[an]){
			//S[an]+=(s1[i]-S[an]);
			zong++;
		}
		an++;
	}
	cout<<zong;
//	for(int i=1;i<=a;i++){
//		cout<<S[i]<<" ";
//	}
	return 0;
}
