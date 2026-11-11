#include<bits/stdc++.h>
using namespace std;
int n,a[300001];
char b[300001];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n/2;i++){
		if(b[i]!=b[n-i+1])    ans+=a[i];
	}
	cout<<ans;
	return 0;
}