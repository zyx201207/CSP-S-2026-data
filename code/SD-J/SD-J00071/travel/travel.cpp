#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		a1=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string temp1=s2.substr(0,2);
	string temp2=s4.substr(0,2);
	if(temp1==temp2){
		a2=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	temp1=s2[2],temp2=s4[2];
	//cout<<temp1<<" "<<temp2<<endl;
	if(temp1=="A"){
		if(temp2=="B"||temp2=="C"){
			a3=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else if(temp1=="B"){
		if(temp2=="C"){
			a3=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
		return 0;
	}
	else if(temp1=="C"){
		if(temp2=="A"||temp2=="B"){
			a3=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else if(temp1=="D"){
		if(temp2=="F"){
			a3=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else{
		cout<<"1100";
		return 0;
	}
	if((temp1=="A"&&temp2=="B")||(temp1=="B"&&temp2=="C")||(temp1=="D"&&temp2=="F")){
		a4=1;
	}
	else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}

