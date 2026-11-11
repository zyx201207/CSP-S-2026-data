#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1,s2;
	int n=0,ans=0;
	int a[100005]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int j=0;
	for(int r=0;r<n;r++){
		s1+=(s[r]*a[r]);
	}
	for(int r=n-1;r>=0;r--){
		s2[j]=s1[r];
		j++;
	}
	for(int i=0;i<n;i++){
		if(s1[i]==s2[i])coutinue;
		else ans++;
	}
	cout<<ans;
	return 0;
}
