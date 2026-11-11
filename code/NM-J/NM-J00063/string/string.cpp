#include <bits/stdc++.h>
using namespace std;
bool hwpd(string s){
	int a=s.size();
	int pd=0;
	for(int i=0;i<=a/2;i++){
		if(s[i]==s[a-1-i]){
			pd++;
		} 
	}
	if(pd==a/2+1){
		return true;
		
	}
    else{
    	return false;
	}
}
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s1;
	cin>>n;
	char a[n+100];
	int b[n+100];
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		for(int j=1;j<=b[i];j++){
		      s1+=a[i];
		} 
	}
     int jh=0;
     int cd=s1.size();
     for(int i=0;i<=cd/2;i++){
     	if(s1[i]!=s1[cd-1-i]){
     		jh++;
		 }
	 }
	 cout<<jh;
}
