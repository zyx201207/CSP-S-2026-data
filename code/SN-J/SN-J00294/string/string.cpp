#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	int n,c=0;
	cin>>n;
	string s;
	string x;
	int a,i;
	for(int j=0;j<n;j++){
		cin>>a>>i;
		for(int g=0;g<a;g++){
			s[g]=i;
		}
		for(int g=a;g>0;g--){
			x[g]=i;
		}
	}
	for(int j=0;j<a;j++){
		if(s[j]==x[j]){
			c=0;
		}else{
			c=c+1;
		}	
	}
	if(c==0){
		cout<<c;
	}else{
		cout<<0;
	}
	return 0;	
}

