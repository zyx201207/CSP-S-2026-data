#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,b,cnt=0;
	string s,c;
	cin>>n;
	for(int i=0;i<n;i++){
		c={};
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			s+=c;
		}
	}
	b=s.size();
	for(int i=0;i < b;i++){
			if(s[i]!=s[b-1-i]){
				++cnt;
				s[i]=s[b-1-i];
			}
		}
	cout<<cnt;
}
