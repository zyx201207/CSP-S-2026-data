#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	for(int i=1;i<s1.size();i++){
		if(s1[i]==s2[i]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(s1[2]="A"&&s2[2]="B"||s1[2]="B"&&s2[2]="C"||s2[2]="A"&&s1[2]="B"||s2[2]="B"&&s1[2]="C"||s1[2]="D"&&s2[2]="F"||s2[2]="D"&&s1[2]="F"){
		cout<<"1";
	}
	else{
		cout<<0;
	}
	return 0;
}