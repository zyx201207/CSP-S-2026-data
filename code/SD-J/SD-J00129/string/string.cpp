#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long cnt;
int n;
long long ans,l;
char s[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		long long x;
		char a;
		scanf("%lld",&x);
		cin>>a;
		l+=x;
		while(x--){
			s[++cnt]=a;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
			s[l+1-i]=s[i];
		}
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
