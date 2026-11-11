#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[100000];
	string c;
	cin>>c;
	string s;
	int l=s.length();
	for(int i=1;i<=n;i++){
		s+=a[i]*c[i];
	}
	if(l%2==0) {
		s=reverse(s);
		cout<<0;
	}
	int cnt=0;
	
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
	
} 
