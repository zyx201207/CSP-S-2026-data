#include <bits/stdc++.h>
using namespace std;
char a[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=1;
	long long ans=0;
	for(int i=0;i<n;i++){
		long long num;
		char word;
		cin>>num>>word;
		for(long long j=1;j<=num;j++){
			a[sum]=word;
			sum++;
		}
	}
	for(long long i=1;i<=sum/2+1;i++){
		if(a[i]!=a[sum-i])ans++;
	}
	cout<<ans;
	return 0;
}