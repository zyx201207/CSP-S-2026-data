#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],L,f[200001],ans,rm,l,r;
char c[200001];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(L>100000000){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];L+=a[i];
		for(int j=0;j<a[i];j++)s=s+c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<L/2;i++)ans+=(s[i]!=s[L-1-i]);
	cout<<ans;
	return 0;
}