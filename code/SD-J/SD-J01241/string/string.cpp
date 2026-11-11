#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],sum[N],ans,flag;
char c[N];
void fun(){
	for(int i=1;i<=sum[n]/2;++i){
		int x=lower_bound(sum+1,sum+n+1,i)-sum;
		int y=lower_bound(sum+1,sum+n+1,sum[n]-i+1)-sum;
		if(c[x]!=c[y]) ans++;
	}
	cout<<ans;
}

void fun_2(){
	for(int i=1;i<=n/2;++i){
		if(c[i]!=c[n-i+1]) ans+=a[i];
	}
	cout<<ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		if(i>=2&&a[i]!=a[i-1]) flag=1;
	}
	if(sum[n]<=1e7) fun();
	else if(!flag) fun_2();
	else cout<<0;
	return 0;
} 
