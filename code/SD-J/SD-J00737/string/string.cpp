#include<bits/stdc++.h>
using namespace std;
long long n,xg=0,a;
string s;
char c;
int h(string a){
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]){
			xg++;
		}
	}
	return xg;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	cout<<h(s);
	return 0;
	/*
	for(long long i=1;i<=n/2;i++){
		if(c1[i]!=c1[n+1-i]){
			r=min(a1[i],a1[n+1-i]);
			l-=(1+r);
			xg+=r;
		}
	}
	for(long long i=1;i<=n-1;i++){
		if(l-r!=1&&c1[i]!=c1[i+1]){
			xg+=(l-1-r);
			l=r;
		}
	}
	cout<<xg;
	*/
}
