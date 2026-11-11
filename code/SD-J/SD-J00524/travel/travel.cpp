#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0;
	char c=0,d=0;
	for(int i=0;i<c1.size();i++){
		if(c1[i]==c2[i]){
			a++;
		}
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s2[i]){
			b++;
		}
		if(s1[i]>='A'&&s1[i]<='F'){
			c=s1[i];
			d=s2[i];
		}
	}
	bool f=0;
	if(a==2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b==2){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='F'&&d>='D'&&d<='F')){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if((char)(c+1)==d||(char)(d+1)==c){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}

