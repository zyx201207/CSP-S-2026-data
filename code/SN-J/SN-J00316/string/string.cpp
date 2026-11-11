#include<bits/stdc++.h>
using namespace std;
string s;
char t;
int n,c,x,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>t; 
		sum+=x;
		for(int j=0;j<x;j++){
			s.push_back(t);
		}
	}
	int c=sum/2;
	for(int i=0,j=sum-1;i<=c;i++,j--){
		if(s[i]!=s[j]){
			c++;
		}
	}
	cout<<c;
}
