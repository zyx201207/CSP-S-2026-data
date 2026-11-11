#include<iostream>
using namespace std;
string s,s1,s2;
long long n;
long long m[300001];
int main(){
	std::ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long nn=0;
	for(int i=0;i<n;i++){
		cin>>m[i];
		cin>>s[i];
		
	}
	
	bool tmp=false;
	for(int i=0;i<n-1;i++){
		if(s[i]!=s[i+1]) tmp=true;
}
    if(!tmp){
    	cout<<0;
    	return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=nn;j<nn+m[i];j++){
			s1[j]=s[i];
		}
		nn+=m[i];
	}
	
	
	for(int i=0;i<nn;i++){
		s2[i]=s1[nn-i-1];
	}
	long long js=0;
	
	for(int i=0;i<nn;i++){
		if(s2[i]!=s1[i]){
			js++;
		}
	}
	cout<<js/2;
	return 0;
}
