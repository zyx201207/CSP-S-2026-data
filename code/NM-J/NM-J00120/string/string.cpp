#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s2;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b;
		while(a--){
			s=s+b;
			s2=b+s2;
		}
	}
	long long cnt=0;
	long long mid=(s.size()+1)/2;
	for(int i=0;i<mid;i++){
		if(s[i]!=s2[i])cnt++;
	}
	cout<<cnt;
	return 0;
}
