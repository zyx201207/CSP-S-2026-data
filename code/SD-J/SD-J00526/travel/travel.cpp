//travel
//8:37 start A
//9:05 wa on A
//9:05 leave A
//9:15 backt A
//9:47 partc A
//9:50 ac on A
//9:52 finish. 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1<s2){
		swap(s1,s2);
		swap(c1,c2);
	}//同一节车厢 
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}//同一排 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}//同一排且同侧 
	//((s1[2]=='A'&&s2[2]=='B')
	//(s1[2]=='A'&&s2[2]=='C')
	//(s1[2]=='B'&&s2[2]=='A')
	//(s1[2]=='B'&&s2[2]=='C')
	//(s1[2]=='C'&&s2[2]=='B')
	//(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}//相邻
	//((s1[0]==s2[0])+(s1[1]==s2[1])+(s1[2]==s2[2])==2
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1)){
			if(s1[2]=='C'&&s2[2]=='D')cout<<0;
			else if(s1[2]=='D'&&s2[2]=='C')cout<<0;
			else cout<<1;
		}else{
			cout<<0;
		}
	}else if(s1[0]==s2[0]&&s1[2]==s2[2]){
		if((s1[1]==s2[1]-1)||(s1[1]==s2[1]+1)){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(s1[1]==s2[1]&&s1[2]==s2[2]&&s1[0]!=s2[0]){
		cout<<0;		
	}else cout<<0;
	return 0;
} 
