#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int s_1[3];
int s_2[3];
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		for(int i=0;i<s1.size();i++){
		s_1[i]=int(s1[i]);	
	}
		for(int i=0;i<s2.size();i++){
		s_2[i]=int(s2[i]);	
	}
		if(s_1[0]==s_2[0] and s_1[1]==s_2[1]){
			cout<<1;
			if((s_1[2]<=67 and s_2[2]<=67) or (s_1[2]>=68 and s_2[2]>=68)){
				cout<<1;
			if((s_1[2]-s_2[2]==1)or(s_1[2]-s_2[2]==-1)){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	}else{
		cout<<0<<0<<0<<0;
	}
	cout<<endl;

	return 0;
}