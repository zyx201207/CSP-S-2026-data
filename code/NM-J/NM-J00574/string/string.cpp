#include<bits/stdc++.h>
using namespace std;
string s,c[200010];
int n;
long long a[200010]; 
int main()
 {
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	 {
 	 	cin>>a[i];
 	 	cin>>c[i];
 	 	for(int j=1;j<=a[i];j++)
 	 		s+=c[i];
	  }
	int len=s.size(),he=0;
	for(int i=1;i<=len/2;i++)
	 	for(int j=len;j>len/2+1;j--)
	 	 	if(s[i]!=s[j]) {s[j]=s[i];he++;}
	cout<<he/2;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
