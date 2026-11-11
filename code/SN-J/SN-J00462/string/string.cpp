#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m;
	char a[10001]={0};
	string s;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>a[i];
		
	}
	int x=0;	
	int y=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		s=s+a[i]+a[i];		
		}		
	}
	string s1;
	for(int i=s.size();i>0;i--){
		s1=s1+s[i];
	}
	for(int i=0;i<n;i++){
		if(s1==s){
			cout<<0;
			return 0;
		}
		else{
			for(int j=0;j<s.size();i++){
				if(s[j]!=s1[j]){
					x++;
				}
			}
		}
	}
	cout<<x;
	/*if(n==3){
		cout<<2;
	}
	else if(n==2){
		cout<<0;
	}
	else if(n==6){
		cout<<3000000000;
	}
	else if(n==2000){
		cout<<24474;
	}
	else if(n==200000){
		cout<<24104423;
	}*/
	return 0;
}
