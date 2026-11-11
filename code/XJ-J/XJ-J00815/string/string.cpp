#include<bits/stdc++.h>
using namespace std;
unsigned long long n,sum;
long long a;
char b;
string s,c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
}