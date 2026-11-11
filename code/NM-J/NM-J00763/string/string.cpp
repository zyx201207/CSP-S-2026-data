#include<bits/stdc++.h>
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
	long long m=s.size()/2;
	int c=0;
	for(long long i=0,j=s.size()-1;  i<m && j>m;i++,j--){
		if(s[i]!=s[j]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
