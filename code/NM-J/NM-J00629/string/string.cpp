#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string f;
long long l,r,ans=0;
char tmp;
long long n,m;
cin>>n;
for(int i=0;i<n;i++){
	cin>>m>>tmp;
	for(long long j=0;j<m;j++){
		 f+=tmp;}
		 }

l=0;
r=f.length()-1;
long long u=f.length()/2;
for(long long i=0;i<u;i++){
	if(f[l+i]!=f[r-i]) {ans++;}
	}
	cout<<ans;
return 0;
}
