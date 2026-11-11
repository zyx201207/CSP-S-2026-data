#include<bits/stdc++.h>
using namespace std;
long long n,a[100005];
char s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	long long sum=0;
	for(long long i=0;i<n;i++){
		sum+=a[i];
	}
	char S[100005];
	for(long long i=0,k=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			S[k]=s[i];
			k++;
		}
	}
	long long ans=0;
	for(long long i=0;i<=(sum-1)/2;i++){
		if(S[i]!=S[sum-i-1]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
