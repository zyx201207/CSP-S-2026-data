#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(long long i=0;i<n;i++){
		int a;
		string s1;
		cin>>a>>s1;
		for(long long j=0;j<a;j++) s=s+s1;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}