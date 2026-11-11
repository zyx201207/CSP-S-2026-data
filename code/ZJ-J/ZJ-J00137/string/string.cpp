#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans,x;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		cin>>c;
		for(long long i=1;i<=x;i++) s=s+c;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
