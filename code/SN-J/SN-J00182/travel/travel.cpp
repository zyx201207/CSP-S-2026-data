#include<bits/stdc++.h>
using namespace std;
string s,b="ABCDF";
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[0]==s[7]&&s[1]==s[8]){
		a[0]=1;
		a[2]=1;
	}else{
		for(int i=0;i<4;i++){
			cout<<a[i];	
		}
		return 0;
	}
	if(s[3]==s[10]&&s[4]==s[11]){
		a[1]=1;
		a[3]=1;
	}else{
		a[2]=0;
		for(int i=0;i<4;i++){
			cout<<a[i];	
		}
		return 0;
	}
	for(int i=0;i<4;i++){
		if(s[5]==b[i]&&s[12]!=b[i+1]){
			if(s[12]!=b[i-1]){
				a[3]=0;
				for(int i=0;i<4;i++){
					cout<<a[i];	
				}
				return 0;
			}
				
		}
		if(s[5]=='C'&&s[12]=='D'){
				a[2]=0;
				a[3]=0;
		}
		if(s[5]=='D'&&s[12]=='C'){
				a[2]=0;
				a[3]=0;
		}
	}
	for(int i=0;i<4;i++)cout<<a[i];
	return 0;
}
