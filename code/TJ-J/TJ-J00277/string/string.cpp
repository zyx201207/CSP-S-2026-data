#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long x;
		string y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			s+=y;
		}
	}
	long long x=0,y=s.size()-1,nam=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[x]!=s[y]){
			nam++;
		}
		x++;
		y--;
	}
	cout<<nam;
	return 0;
}
