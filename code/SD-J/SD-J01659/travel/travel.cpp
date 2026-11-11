#include<bits/stdc++.h>
using namespace std;
bool check1(string x,string y){
	if(x[2]=='A'){
		return y[2]=='B'||y[2]=='C';
	}else if(x[2]=='B'){
		return y[2]=='A'||y[2]=='C';
	}else if(x[2]=='C'){
		return y[2]=='B'||y[2]=='A';
	}else if(x[2]=='D'){
		return y[2]=='F';
	}else{
		return y[2]=='D';
	}
}
bool check2(string x,string y){
	if(x[2]=='A'){
		return y[2]=='B';
	}else if(x[2]=='B'){
		return y[2]=='A'||y[2]=='C';
	}else if(x[2]=='C'){
		return y[2]=='B';
	}else if(x[2]=='D'){
		return y[2]=='F';
	}else{
		return y[2]=='D';
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}else{
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			if(!check1(s2,s4)){
				cout<<"1100";
				return 0;
			}else{
				if(!check2(s2,s4)){
					cout<<"1110";
					return 0;
				}else{
					cout<<"1111";
				}
			}
		
		}else{
			cout<<"1000";
			return 0;
		}
	}
	return 0;
}
