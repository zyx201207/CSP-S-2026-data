#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200086];
char c[200086];
int z[100086];
int gcd(int a,int b){
	if(!a||!b)return 1;
	if(a%b)return gcd(b,a%b);
	else return b;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,t=0,minn=1000000086;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		minn=min(minn,a[i]);
		t+=a[i];
		
	}
	int gcdx=gcd(a[1],a[2]);
	for(int i=3;i<=n;i++)gcdx=gcd(gcdx,a[i]);
	for(int i=1;i<=n;i++){
		a[i]/=gcdx;
		for(int j=1;j<=a[i];j++)s+=c[i];	
	}
	int cnt=0;
	t/=gcdx;
	for(int i=0;i<=t/2-1;i++){
		if(s[i]!=s[t-i-1])cnt+=1;
	}
	cout<<cnt*gcdx;
	return 0;
}
