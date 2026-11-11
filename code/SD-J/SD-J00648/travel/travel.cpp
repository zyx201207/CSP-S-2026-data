#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	int n=c1.size(),m=s1.size();
	for(int i=0;i<n;i++){
		if(c1[i]!=c2[i]){
			f=1;
		}
	}
	if(f){
		cout<<"0000";
		return 0;
	}
	f=0;
	for(int i=0;i<m-1;i++){
		if(s1[i]!=s2[i]){
			f=1;
//			cout<<i<<" ";
		}
	}
	if(f){
		cout<<"1000";
		return 0;
	}
	f=0;
	if((s1[m-1]=='A'||s1[m-1]=='B'||s1[m-1]=='C')&&(s2[m-1]=='A'||s2[m-1]=='B'||s2[m-1]=='C')){
		f=1;
	}else if((s2[m-1]=='D'||s2[m-1]=='F')&&(s1[m-1]=='D'||s1[m-1]=='F')){
		f=1;
	}
	if(f==0){
		cout<<"1100";
		return 0;
	}
	f=0;
	if((s1[m-1]=='A'&&s2[m-1]=='B')||(s1[m-1]=='B'&&(s2[m-1]=='A'||s2[m-1]=='C'))||(s1[m-1]=='C'&&s2[m-1]=='B'))
	{
		f=1;
	}else if((s1[m-1]=='D'&&s2[m-1]=='F')||(s2[m-1]=='D'&&s1[m-1]=='F')){
		f=1;
	}
	if(f){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
