#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	long long a;
	char b;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a);
		scanf("%s",&s);
		s.append(a,b);
	}
	long long l=0;
	long long len=s.size();
	long long r=len-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
