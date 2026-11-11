#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,t=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long  a;
		char c;
		cin>>a;
		cin>>c;
		while(a--){
			s+=c;
			t++;
		}
	}
	long long l=0,r=t-1,num=0;
	while(l<=r){
		if(s[l]!=s[r]){
			num++;
		}
	    l++;
		r--;
	 }
	cout<<num;
	return 0;
}
