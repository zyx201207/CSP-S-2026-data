#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2;
	string s1,s2;
	cin>>n1>>s1>>n2>>s2;
	if(n1==n2)cout<<1;
	else {
	    cout<<"0000";	
	    return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='c')&&(s2[2]=='D'||s2[2]=='E')||(s2[2]=='A'||s2[2]=='B'||s2[2]=='c')&&(s1[2]=='D'||s1[2]=='E')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2])cout<<1;
	else cout<<0;
	return 0;
} 
