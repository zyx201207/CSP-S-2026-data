#include<bits/stdc++.h> 
using namespace std;
string s1,s2,c1,c2;
bool f = 1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
	for(int i = 0;i < 2;i++)//同一节车厢 
	{
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i = 0;i < 2;i++)//同一排 
	{
		if(s1[i]!=s2[i]){
			cout<<"0";
			f = 0;
		}
	}
	if(f){
		cout<<"1";
    }
	if(s1[2] == 'A'){
		if(s2[2] == 'B'){
			cout<<"11";
		}else if(s2[2] == 'C'){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}
	else if(s1[2] == 'B'){
		if(s2[2] != 'A'||s2[2] != 'C'){
			cout<<"00";
		}else{
			cout<<"11";
		}
	}
	else if(s1[2] == 'C'){
		if(s2[2] == 'A'){
			cout<<"10";
		}else if(s2[2] == 'B'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
	else if(s1[2] == 'D'){
		if(s2[2] != 'F'){
			cout<<"00";
		}else{
			cout<<"11";
		}
	}
	else if(s1[2] == 'F'){
		if(s2[2] != 'D'){
			cout<< "00";
		}else{
			cout<<"11";
		}
	}
	return 0;
}
