#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num1=0;cin>>n;string s;
    for(int i=0;i<n;i++){
		int x;cin>>x;
		string d;
		cin>>d;
		for(int i=0;i<x;i++){
			s+=d;
		}
	}for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			num++;
		}
	}cout<<num;return 0;
}

	

