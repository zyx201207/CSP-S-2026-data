#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	for(int i=0;i<=c1.size()-1;i++){    //同一节车厢 
		if(c1[i]!=c2[i])f=1;
	}
	if(f==1){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	f=0;
	for(int i=0;i<=s1.size()-2;i++){   //同一排 
		if(s1[i]!=s2[i])f=1;
	}
	if(f==1){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){  //同一侧 
		if(s2[2]=='D' || s2[2]=='F' && f==1)cout<<0;
		else cout<<1;
	}
	else if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C' ){  //同一侧 
		if(s1[2]=='D' || s1[2]=='F' && f==1)cout<<0;
		else cout<<1;
	}
	//相邻 
	if(s1[2]=='A'){
		if(s2[2]=='B')cout<<1;
		else cout<<0;
	}
	else if(s1[2]=='B'){
		if(s2[2]=='C' || s2[2]=='A')cout<<1;
		else cout<<0;
	}
	else if(s1[2]=='C'){
		if(s2[2]=='B')cout<<1;
		else cout<<0;
	}
	else if(s1[2]=='D'){
		if(s2[2]=='F')cout<<1;
		else cout<<0;
	}
	else if(s1[2]=='F'){
		if(s2[2]=='D')cout<<1;
		else cout<<0;
	}
return 0;
}

