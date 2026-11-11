#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1+1>>s1+1>>c2+1>>s2+1;
	bool flag=0;
	for(int i=1;i<=2;i++){
		if(c1[i]!=c2[i]){
		   cout<<"0000";
		   return 0;
		}
        
	}
	cout<<'1';
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
	   cout<<'1';
	   flag=1;
	}
	else cout<<'0';
	
	if(s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C'&&flag==1) cout<<'1';
	else if(s1[3]>='D'&&s1[3]<='F'&&s2[3]>='D'&&s2[3]<='F'&&flag==1) cout<<'1';
	else{
	cout<<'0';
	flag=0;
	}
	
	if(flag==1){
		if(abs(s1[3]-s2[3])==1) cout<<'1';
		else cout<<'0';
	}
	else cout<<'0';
	return 0;
}