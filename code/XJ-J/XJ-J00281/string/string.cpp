#include <bits/stdc++.h>
using namespace std;
string s,s2;
char b;
long long a,n,k,l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(;n>=0;n--){
		cin>>a;
		cin>>b;
		for(int i=1;i<=a;i++){
			s=s+b;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		s2[k]=s[i];
		k++;
	}
	for(int i=0;i<k;i++){
		if(s[i]!=s2[i]){
			l++;
		}
	}
	cout<<l/2;
	return 0;
}