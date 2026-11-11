#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
    long x=0;
    int a[n];
    char p[n];
	for(int i=1;i<=n;i++){
//		long long a;
//		char p;
		cin>>a[i]>>p[i];
//		for(int j=x;j<x+a;j++){
//			s+=p;
//		}
//		x+=a;
	}
	for(long long i=1;i<=n;i++){
	    for(long long j=x;j<x+a[i];j++){
		    s+=p[i];
		}
		x+=a[i];
	}
	int ans=0;
    string s1;
	for(int i=s.size();i>=0;i--){
		s1+=s[i-1];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s1[i]) ans++;
	}
	cout<<ans/2;
	return 0;
}
