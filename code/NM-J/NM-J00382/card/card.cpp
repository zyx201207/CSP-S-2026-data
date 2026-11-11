#include <bits\stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	char r1;
	string s1;
	char r2;
	string s2;
	bool f;
	bool f1;
	bool f2;
	bool f3;
	cin>>r1>>s1>>r2>>s2;
	if(r1==r2){
		f=true;
	}else if(r1=='01'||r1=='16'||r2=='01'||r2=='16'){
		f=false;
	}else{
		f=false;
	}
	if(f=true){
		cout<<1;
	}if(f==false){
		cout<<0;
	}
	int n=0;
	int m=0;
	vector<int>a;
	vector<int>b;
	for(int i=0;i<s1.length ()-1;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			 n=s1[i]-'0';
			 a.push_back(n);
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			 m=s2[i]-'0';
			 b.push_back(m);
		}
	}
	if(n==m){
		f1=true;
	}else{
		f1=false; 
	} 
	if(f1=true){
		cout<<1;
	}if(f1==false){
		cout<<0;
	}

	return 0;
}
