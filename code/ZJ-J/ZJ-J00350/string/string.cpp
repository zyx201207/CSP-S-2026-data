#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
	if(x<y)swap(x,y);
	while(y!=0){
		x%=y;
		if(x<y)swap(x,y);
	}
	return x;
}
long long n,m,t;
long long sum,ans;
int a[200005];
int x[200005];
char y[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(i!=1)t=gcd(x[i],t);
		else t=x[i];
	}
	for(int i=1;i<=n;i++){
		x[i]/=t;
		sum+=x[i];
		for(int j=1;j<=x[i];j++)s+=y[i];
	}
	for(int i=0;i<sum/2;i++)ans+=(s[i]!=s[sum-i-1]);
	printf("%lld",ans*t);
}
