#include <bits/stdc++.h>
using namespace std;
long long n,a,num;
char c;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a>>c;
		while (a--){
			s+=c;
		}
	}
	for (long long i=0;i<(long long)s.length()/2;i++){
		if(s[i]!=s[(long long)s.length()-1-i]){
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
