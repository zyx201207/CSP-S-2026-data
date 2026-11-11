#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;//p1
	string sum1,sum2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		cout<<"1";
	} 
	for(int i=0;i<=2;i++){
		if(s1[i]!='A'&&s1[i]!='B'&&s1[i]!='C'&&s1[i]!='D'&&s1[i]!='F'){
			sum1[i]=s1[i];
		}
		if(s2[i]!='A'&&s2[i]!='B'&&s2[i]!='C'&&s2[i]!='D'&&s2[i]!='F'){
			sum2[i]=s2[i];
		}
	}//ÇóÅÅ 
	if(sum1[0]==sum2[0]&&sum1[1]==sum2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char ans1,ans2; 
	for(int i=0;i<=2;i++){
		if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'||s1[i]=='D'||s1[i]=='F'){
			ans1=s1[i];
		}
		if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C'||s1[i]=='D'||s1[i]=='F'){
			ans2=s2[i];
		}
	}//ÇóÎ» 
	if((ans1=='A'&&(ans2=='B'||ans2=='C'))||(ans1=='B'&&(ans2=='A'||ans2=='C'))||(ans1=='C'&&(ans2=='A'||ans2=='B'))||(ans1=='D'&&ans2=='F')||(ans1=='F'&&ans2=='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((ans1=='A'&&ans2=='B')||(ans1=='B'&&(ans2=='A'||ans2=='C'))||(ans1=='D'&&ans2=='F')||(ans1=='F'&&ans2=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

