#include<bits/stdc++.h>
using namespace std;
char c[100000001];
set<pair<int,int>>S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int L=0;
	for(int i=1;i<=n;i++){
		int l;char a;
		cin>>l>>a;
		for(int j=1;j<=l;j++){
			L++;
			c[L]=a;
						
		} 
	}long long ans=0;
	for(int i=1;i*2<=L;i++){
		if(c[i]!=c[L+1-i])ans++;
	}cout<<ans<<'\n';
}
