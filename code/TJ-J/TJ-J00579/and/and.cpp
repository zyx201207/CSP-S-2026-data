#include<bits/stdc++.h>
using namespace std;
int n,m,mx=-1;
int a[200005];
string s="";
int he(int n1,int n2){
	string n1s,n2s,zg;
	while(n1!=0){
		string ls="";
		ls+=(n1%2+'0');
		n1s=ls+n1s;
		n1/=2;
	}
	while(n2!=0){
		string ls="";
		ls+=(n2%2+'0');
		n2s=ls+n2s;
		n2/=2;
	}
	if (n1s.size()>n2s.size()){
		swap(n1s,n2s);
	}
	for (int i = 1;i <= n1s.size()-n2s.size();i++) n2s+='0';
	for (int i = 0;i < n1s.size();i++){
		if (n1s[i]==n2s[i]&&n1s[i]==1){
			zg+='1';
		}
		else zg+='0';
	}
	int fb=1,rt=0;
	for (int i = 0;i < zg.size();i++){
		rt+=(zg[i]-'0')*fb;
		fb*=2;
	}
	return rt;
}
void dg(int j_){
	if (j_==0){
		int dq=1;
		for (int i = 0;i < s.size();i++){
			dq=he(dq,(s[i]-'0'));
		}
		if (dq>mx) mx=dq;
	}
	else{
		for (int i = 1;i <= n;i++){
			bool f=true;
			for (int j = 0;j < s.size();j++){
				if (i==s[j]-'0') f=false;
			}
			if(f){
				s+=(i+'0');
				dg(j_-1);
				s=s.substr(0,s.size());
			}
		}
	}
	
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i = 1;i <= n;i++){
    	cin>>a[i];
	}
	dg(m);
	cout<<mx;
	return 0;
}
