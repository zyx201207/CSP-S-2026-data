#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","w",stdin);
	freopen("string.in","r",stdout);
	int n;
	string s="";
	long long x;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int j=1;j<=x;j++) s+=a;
	}
	long long i=0,j=s.size()-1;
	long long sum=0;
	for(i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]) sum++;
	}
	cout<<sum;
	return 0;
}
