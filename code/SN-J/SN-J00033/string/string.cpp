#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s.size()%2==0){
			if(s[i]==s[s.size()-1-i]){
				cout<<"yes";
			}
			else{
				cout<<"no";
			}
			return 0;
		}
		else{
			if(s[i]==s[s.size()-1-i]){
				cout<<"yes";
			}
			else{
				cout<<"no";
			}
			return 0;
		}
	} 
	return 0;
}
