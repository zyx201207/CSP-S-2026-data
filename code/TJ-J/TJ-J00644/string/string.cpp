#include<bits/stdc++.h>
using namespace std;

long long n,ans,l,r;
string s;//从零开始 
string ss;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
		}
	}
	long long len=s.size();
	l=0,r=len-1,ans=0;
	for(int i=0;i<len/2;i++){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	} 
	cout<<ans;//样例3 5有问题 
	
	return 0;
} 
