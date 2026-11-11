#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a,x=0;
	string b,s,s2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=s.size(),j=1;i>0;i--,j++){
		s2[i]=s[j];
	}
	//for(int i=1;i<=s.size();i++){
	//	if(s[i]!=s2[i])
	//}
	return 0;
}