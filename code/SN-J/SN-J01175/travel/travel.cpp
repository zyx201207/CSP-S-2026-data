#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3,ans4;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		ans1=1;
	}else{
		cout<<"0";
	}
	for(int i=0;i<2;i++){
		if(a2[i]==b2[i]){
			ans2++;
		}
	}
	//if(abs(a2[2]-b2[2])<=1){
	//	ans3=1;
	//}
	if(a2[2]=='A'&&(b2[2]=='B'||b2[2]=='C')) ans3=1;
	if(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C')) ans3=1;
	if(a2[2]=='C'&&(b2[2]=='A'||b2[2]=='B')) ans3=1;
	if(a2[2]=='D'&&b2[2]=='F') ans3=1;
	if(a2[2]=='F'&&b2[2]=='D') ans3=1;
	
	if(a2[2]=='A'&&b2[2]=='B') ans4=1;
	if(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C')) ans4=1;
	if(a2[2]=='C'&&b2[2]=='B') ans4=1;
	if(a2[2]=='D'&&b2[2]=='F') ans4=1;
	if(a2[2]=='F'&&b2[2]=='D') ans4=1;

	if(ans1==1&&ans2==2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(ans1==1&&ans2==2&&ans3==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(ans4==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
