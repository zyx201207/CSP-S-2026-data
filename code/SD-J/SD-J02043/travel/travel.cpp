#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[10000001];
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else {
		cout<<"0000";
		return 0;
	} 
	for(int i=0;i<s2.size()-1;i++){
		if(s2[i]!=s4[i]){
			cout<<"000";
			return 0;
		}
		if(i==1){
			cout<<1;
		}
	}
	if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')){
		cout<<1;
	}else {
		cout<<"00";
		return 0;
	}
	if(abs(int(s2[2]-s4[2]))==1){
		cout<<1;
	}else cout<<0;
	return 0;
} 
