#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	string s="";
	char x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s+=x;
		}
	}
	long long l=0,r=s.size()-1;
	long long sum=0;
	while(l<=r){
		if(s[l]!=s[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
