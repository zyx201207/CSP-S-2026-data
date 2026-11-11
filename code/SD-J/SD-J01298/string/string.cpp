#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	string s="";
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long num=0;
	for (long long i=0;i<s.length()/2;i++){
		if (s[i]!=s[s.length()-1-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
