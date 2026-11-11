#include<bits/stdc++.h>
using namespace std;
long long n,b=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char c;
	string s;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	long long  l=s.size()/2;
	string s1=s;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<l;i++){
		if(s[i]!=s1[i]){
			b++;
		}
	}
	cout<<b;
	return 0;
}
