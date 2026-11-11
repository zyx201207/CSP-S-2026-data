#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a[1000001],c[1000001],sum=0,b[27],maxx=-998877;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]==s[i+1]) cout<<"0";
		else b[c[i]]++;
	}
	for(int i=1;i<=27;i++){
		maxx=max(maxx,b[i]);
	}
	cout<<s.size()-maxx;
	return 0;
}
