#include<bits/stdc++.h>
using namespace std;
int n;
struct nod{
	char a;
	long long b;
}c[200001];
long long sz;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].b>>c[i].a;
		sz+=c[i].b;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1].a==c[2].a)cout<<0;
		else cout<<min(c[1].b,c[2].b);
		return 0;
	}
	string s1="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i].b;j++)s1+=c[i].a;
	}
	long long ans=0;
	for(int i=0;i<sz/2;i++)if(s1[sz-i-1]!=s1[i])ans++;
	cout<<ans;
	return 0;
}
