#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,cc;
	char s1[3],s2[3];
	cin>>c>>s1>>cc>>s2;
	if(c==cc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]=='D'&&s2[2]=='C'){
		cout<<0<<0;
		return 0;
	}
	if(s1[2]=='C'&&s2[2]=='D'){
		cout<<0<<0;
		return 0;
	}
	if(s1[2]!='D'&&s2[2]!='F'){
		if(s1[2]!='D'&&s2[2]!='F'){
			if(s1[2]>s2[2]&&s1[2]-s2[2]==1){
				cout<<1<<1;
			}else if(s1[2]<s2[2]&&s2[2]-s1[2]==1){
				cout<<1<<1;
			}else{
				cout<<1<<0;
			}
			return 0;
		}
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		if(s1[2]=='D'&&s2[2]=='F'){
			cout<<1<<1;
			return 0;
		}
	}
	return 0;
} 
