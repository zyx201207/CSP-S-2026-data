#include<bits/stdc++.h>
using namespace std;
int a[100009]; 
bool hw(string s1){
	for(int i=0;i<s1.size()/2;i++){
		for(int j=s1.size()-1;j>s1.size()/2+1;j--){
			if(s1[i]!=s1[j]){
				return 0;
			}
		}
		
	}
	return 1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
	} 
	string s1;
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s1[k]=s[i];
			k++;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[0]>=a[1]){
			cout<<a[1];
			return 0;
		}else{
			cout<<a[0];
			return 0;
		}
	}
	return 0;
}
