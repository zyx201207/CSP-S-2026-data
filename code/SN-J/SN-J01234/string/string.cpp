#include<bits/stdc++.h>
using namespace std;
int n,a[200001],b[27];
char s[200001];
bool c=1;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<n;i++){
		if(s[i]!=s[i+1]){
			c=0;
			break;
		}
	} 
	if(c){
		cout<<0;
	}
	return 0;
}
