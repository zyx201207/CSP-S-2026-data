#include<bits/stdc++.h>
using namespace std;
long long c[200010];
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>c[i]>>a[i];
	long long l=n;
	for(int i=1;i<=n;){
		if(i>=l)	break;
		long long p=min(c[i],c[l]);
		if(a[i]!=a[l])	ans+=p;
		c[i]-=p,c[l]-=p;
		if(c[i]==0)	i++;
		if(c[l]==0)	l--;
	}
	cout<<ans;
	return 0;
}

