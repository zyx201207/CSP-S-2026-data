#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
char b[N];
string s=" ";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s+=b[i];
	int ans=0;
	int l=s.size()-1;
	for(int i=1;i<=l;i++)
		if(s[i]!=s[l-i+1])
			ans++;
	cout<<ans/2;
	return 0; 
} 
