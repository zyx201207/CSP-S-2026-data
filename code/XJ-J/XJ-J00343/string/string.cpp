#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long num=0;
	for(int i=1;i<=n/2;i++){
		if(a[i]-a[n-i+1]==num || a[n-i+1]-a[i]==num) continue;
		if(c[i]!=c[n-i+1]){
			ans+=max(a[i],a[n-i+1]);
			num=max(a[i],a[n-i+1])-min(a[i],a[n-i+1]);
		}
	}
	cout<<ans;
	return 0;
} 
