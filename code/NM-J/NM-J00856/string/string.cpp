#include<bits/stdc++.h>
using namespace std;
string s[200005];
int n,m[200005],ans,l,j,x;
char s1,p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>j>>p;
		l +=j;
		x=p-'a';
		for(int v=0;v<j;v++){
			m[v]=x;};};
	for(int i=0;i<l;i++){
		if(m[i]!=m[l-i-1])ans++;}; 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
