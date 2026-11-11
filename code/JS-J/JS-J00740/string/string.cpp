#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int  a;
		char c;
		scanf("%d",&a);
		cin>>c;
		for(int j=0;j<a;j++)s+=c;
	}
	int y=s.size(),x=s.size()/2;
	int cnt=0;
	for(int i=0;i<x;i++){
		if(s[i]!=s[y-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
