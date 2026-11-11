#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s1="";
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s1+=c;
		}
	}
	int sum=0;
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-1-i]){
			sum++;
		}
	}cout<<sum;
	return 0;
} 
