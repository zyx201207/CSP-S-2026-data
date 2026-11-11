#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,ss;
string c,cc;
bool f1,f2,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>c>>ss>>cc;
	if(s==ss){
		cout<<1;
		f1=1;
	}else{
		cout<<0;
	}
	if(f1==0){
		cout<<0<<0<<0;
		return 0;
	}
	if(c[0]==cc[0]&&c[1]==cc[1]){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	if(f2==0){
		cout<<0<<0;
		return 0;
	}
	if((((c[2]=='A'||c[2]=='B')||c[2]=='C')&&((cc[2]=='A'||cc[2]=='B')||cc[2]=='C'))||((c[1]=='D'||c[1]=='F')&&(cc[1]=='D'||cc[1]=='F'))){
		cout<<1;
		f=1;
	}else{
		cout<<0;	
	} 
	if(f==0){
		cout<<0;
	}else{
		if(c[2]=='F'||cc[2]=='F'){
			cout<<1;
		}else if((c[2]=='A'&&cc[2]=='C')||(cc[2]=='A'&&c[2]=='C')){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}

