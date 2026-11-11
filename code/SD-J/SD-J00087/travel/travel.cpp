#include<bits/stdc++.h>
using namespace std;
int n,m;//long long
string st,sr,sst,ssr;
int slove(string s){
	int res=0;
	if(s[0]==1)res+=10;
	res+=s[1]-'0';
	return res;
}
bool pd(string s,string ss){
	int x=1,y=1;
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')x=0;
	if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')y=0;
	if(x==y)return 1;
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>st>>sr>>sst>>ssr;
	if(st!=sst){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	n=slove(sr);
	m=slove(ssr);
	if(n!=m){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(!pd(sr,ssr)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(sr[2]-ssr[2])>1){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
} 
