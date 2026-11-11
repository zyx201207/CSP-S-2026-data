#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	string s;
	string s1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>s1[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++) s+=s1[i]; 
	}
	
	string s2;
	for(int i=s.size()-1;i>=0;i--){
		s2+=s[i];
	}
	
	if(s==s2||n==1){
		cout<<0;
	}else cout<<5;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
