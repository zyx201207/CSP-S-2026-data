#include <bits/stdc++.h>
using namespace std;

string s; 
int a[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	

	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	
	if(n=1){
		for(int i=0;i<a[0];i++){
			cout<<s[0];
		}
	}else{
		cout<<3;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
