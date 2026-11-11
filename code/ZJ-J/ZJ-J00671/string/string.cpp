#include<bits/stdc++.h>
using namespace std;
long long n,num;
long long a;
char b;
string s;
int main(){
	cin>>n;
	while(n--){
		cin>>a>>b;
		while(a--)s+=b;
	}
	long long sl=s.size();
	for(long long i=0;i<=sl/2;i++){
		if(s[i]!=s[sl-i-1])num++;
	}
	cout<<num;
	return 0;
}
