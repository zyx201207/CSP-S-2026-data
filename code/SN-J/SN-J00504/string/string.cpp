#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	int j=1;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long size=(long long)s.size();
	long long l=0,r=size-1;
	long long cnt=0;
	while(l<r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			cnt++;
			l++;
			r--;
		}
		else{
			l++;
			r--;
			continue; 
		}
	}
	cout<<cnt<<endl;
	return 0;
}
