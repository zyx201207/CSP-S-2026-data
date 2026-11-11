#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2,a,b;
	cin>>s1>>s2>>c1>>c2;
	long long n=s2.size();
	if(s1==c1&&s1!="01"&&c1!="01"&&s1!="16"&&c1!="16"){
		cout<<'1';
		for(int i=0;i<n-1;i++){
		a+=s2[i];
		b+=c2[i];
	}
	if(a==b){
		cout<<1;
		if((s2[n-1]-'0'>=17&&s2[n-1]-'0'<=19&&c2[n-1]-'0'>=17&&c2[n-1]-'0'<=19)){
		cout<<1;
		if(s2[n-1]-'0'+1==c2[n-1]-'0'||s2[n-1]-'0'-1==c2[n-1]-'0')cout<<1;
		else cout<<0;
	}
	else if(s2[n-1]-'0'==22){
		if(c2[n-1]-'0'==20)cout<<11;
		else cout<<0;
	}
	else if(c2[n-1]-'0'==22){
		if(s2[n-1]-'0'==20)cout<<11;
		else cout<<0;
	}
	else cout<<"00";
	}
	else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
