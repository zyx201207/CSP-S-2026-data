#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int a;
	char c;
	
}s[N];
string z;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
		for(int j=1;j<=s[i].a;j++)	z+=s[i].c;
	}
	for(int i=0;i<sum/2;i++){
		if(z[i]!=z[sum-i-1])	ans++;
	}
	cout<<ans;
	return 0;
}
