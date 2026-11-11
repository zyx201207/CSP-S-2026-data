#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			cout<<0;f=1;
		}
	}
	if(!f)cout<<1;
	if(f)cout<<0;
	else{
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<0;f=1;
			}
		}
		if(!f)cout<<1;
	}	
	if(!f&&((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))){
		cout<<1;
	}else{
		f=1;
		cout<<0;
	}
	if(!f&&(s1[2]-1==s2[2]||s1[2]+1==s2[2]||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
