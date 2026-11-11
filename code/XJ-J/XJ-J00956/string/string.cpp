#include<iostream>
using namespace std;
long long n;
int a;
string s="";
char b;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++)s+=b;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[s.size()-i-1]!=s[i])sum++;
	}
	cout<<sum;
}