#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s[10005]={};
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		string q;
		cin>>q;
		string s1="";
		for(int j=1;j<=a;j++){
			s1+=q;
		}
		s[i]=s1;
	} 
	string s2="";
	for(int i=1;i<=n;i++){
		s2+=s[i];
	}
	int l=0;
	int r=s2.size()-1;
	int ans=0;
		while(l<r){
			if(s2[r]!=s2[l]) ans++;
			l++;
			r--;
		}
		cout<<ans;
	return 0;
}
