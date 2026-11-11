#include<bits/stdc++.h>
using namespace std;
string n,a,m,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>s;
	if(n==m){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[1]==s[1]){
		if(a[0]==s[0]){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	if((a[2]<='C' && s[2]>='D') || (a[2]>='D' && s[2]<='C')){
		cout<<"00";
	}else{
		cout<<'1';
		if(abs(a[2]-s[2])==1){
			cout<<'1';
		}else{
			cout<<'0';			
		}
	}
	return 0;
} 
