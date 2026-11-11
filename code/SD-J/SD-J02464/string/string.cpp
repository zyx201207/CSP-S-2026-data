#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long x;
		string y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			s+=y;
		}
	}
	long long o=0;
	long long l=0;
	long long r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			o++;
		}
		l++;
		r--;
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
