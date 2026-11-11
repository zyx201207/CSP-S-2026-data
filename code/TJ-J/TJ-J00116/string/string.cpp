#include<bits/stdc++.h>
using namespace std;
long long a[200002],n,ans;
char b[200002];
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=0;j<a[i];j++)c+=b[i];
	}
	for(long long i=0;i<c.size()/2;i++){
		if(c[i]!=c[c.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
