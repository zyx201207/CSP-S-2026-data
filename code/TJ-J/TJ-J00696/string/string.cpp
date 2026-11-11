#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai,cnt=0,l=0,q=0;
	cin>>n;
	string ci,s;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		for(int j=1;j<=ai;j++){
			s=s+ci;
		}
	
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]==s[i+1]){
			cnt=cnt+1;
		}
		l=l+1;
	}
	if(l=cnt+1){
		cout<<0;
	}
	for(int i=1;i<=s.size();i++){
		for(int j=s.size();j>=1;j--){
			if(s[i]!=s[j]){
				q=q+1;
			}
		}
	}
	cout<<q;

	return 0;
}
