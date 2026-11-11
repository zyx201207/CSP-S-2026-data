#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cout<<1111;
	string c1, c2;
	string si[5];
	string s2[5];
	for(int i=0;i<s1.size;i++){
		cin>>s1[i];
	}
	for(int j=0;j<s2.size;j++){
		cin>>s1[j];
	}
	cin>>c1>>c2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if(s1[2]!='C'&&s2[2]!='D'){
		cout<<1;
	}
	if({s1[2]==s2[2]+1}||(s1[2]==s2[2]-1)) cout<<1;
	else cout<<0<<0;
	
	
	
	
	return 0;
}