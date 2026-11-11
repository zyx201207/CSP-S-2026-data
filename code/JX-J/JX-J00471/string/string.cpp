#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string,in","r",stdin);
	freopen("string.out","w",stdout);
	long long b[10000000009];
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i-1])ans++;
	}cout<<ans;
	return 0;
}
