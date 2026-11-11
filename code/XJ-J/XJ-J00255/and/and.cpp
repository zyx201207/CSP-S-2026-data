#include <bits/stdc++.h>
using namespace std;
long long a[20005];
string xh;
cmp(int x,int y){
	if(x>y){
		return 1;
	}else{
		return 0;
	}
	if(x==y){
		return 1;
	}
}
string ejz(int n){ 
	string s1;
	char c;
	int x;
	x=n%2;
	c=x+'0';
	s1=c+s1;
	n/=2;
	return s1;
}
int awy(string w1,string w2){
	string w3;
	for(int i=0;i<w1.size();i++){
		if(w1[i]==w2[i]){
			w3[i]==1;
		}else{
			w3[i]==0;
		}
	}
	int num;
	int p=0;
	for(int i=0;i<w3.size()-1;i++){
		num+=w3[i]*pow(p,2);
		p++; 
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	string a1=ejz(a[0]);
	string a2=ejz(a[1]);
	if(a1.size()%4==1){
		a1="0"+a1; 
	}
	if(a1.size()%4==2){
		a1="00"+a1; 
	}
	if(a1.size()%4==3){
		a1="000"+a1; 
	}
	if(a2.size()%4==1){
		a2="0"+a2; 
	}
	if(a2.size()%4==2){
		a2="00"+a2; 
	}
	if(a2.size()%4==3){
		a2="000"+a2; 
	}
	cout<<awy(a1,a2);
	return 0;
}
