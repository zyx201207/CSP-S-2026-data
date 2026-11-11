#include<bits/stdc++.h>
using namespace std;

long long n,a[200002],l,t;
char c[200002];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
			l++;
		}
	}
	
	for(int i=0;i<=l/2;i++){
		if(s[i]==s[l-i-1]) continue;
		else t++;
	}
	
	cout<<t;
	
	return 0;
}//Trick||Treat!
