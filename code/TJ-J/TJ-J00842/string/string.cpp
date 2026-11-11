#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[10001]={};
	char b[10001]={};
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s=s+b[i];
		}
	}
	int cnt=0;
	
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				cnt++;
				s[i]=s[s.size()-i-1];
			}
		}
		cout<<cnt;
	return 0;
}
