#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1=0,f2=0,f3=0,f4=0;
bool check3(string s1,string s2){
	switch(s1[2]){
		case 'A':
		case 'B':
		case 'C':
			if(s2[2]!='D'&&s2[2]!='F'){
				return 1;
			}
			else{
				return 0;
			}
		case 'D':
			if(s2[2]=='F'){
				return 1; 
			}	
			else{
				return 0;
			}
		case 'F':
			if(s2[2]=='D'){
				return 1; 
			}	
			else{
				return 0;
			}
	}
}
bool check4(string s1,string s2){
	switch(s1[2]){
		case 'A':
			return s2[2]=='B';
		case 'B':
			return s2[2]=='A'||s2[2]=='C';
		case 'C':
			return s2[2]=='B';
		case 'D':
		case 'F':
			return 1;
	}
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//两张车票对应的座位是否在同一节车厢;
	if(c1==c2){
		//cout<<"1";
		f1=1;
	}
//	else{
//		cout<<"0";
//	}
	//两张车票对应的座位是否在同一节车厢的同一排;
	if(f1==1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		//cout<<"1";
		f2=1;
	}
//	else{
//		cout<<"0";
//	}
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧;
	if(f2==1&&check3(s1,s2)){
		//cout<<"1";
		f3=1;
	}
//	else{
//		cout<<"0";
//	}
	//两张车票对应的座位是否相邻;
	if(f3==1&&check4(s1,s2)){
		//cout<<"1";
		f4=1;
	}
//	else{
//		cout<<"0";
//	}
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

