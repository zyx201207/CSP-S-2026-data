#include<bits/stdc++.h>
using namespace std;
string s,b;
int n,x,op,ans;
string y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		for(int j=0;j<x;j++){
			s+=y;
		}	
	}
	int t=s.size();
	op=0;
	for(int i=n;i>0;i--){
		b[op++]=s[i];
	}
	for(int i=0;i<t/2;i++){
		if(s[i]!=b[i])ans++;
	}
	cout<<ans;
	return 0;
} 
