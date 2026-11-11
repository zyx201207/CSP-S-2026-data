#include<bits/stdc++.h>
#define int long long 
using namespace std;
int  n,a[300005],gg;
char b[300005];
int c[300005];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=c[i-1]+a[i];
	}
	int t=1,w=c[n-1]+1;//zifu
	int f=1,k=n;//shuzu
	while(f<k){
		int x;
		x=min(c[f]-t+1,w-c[k-1]+1);
		if(b[f]!=b[k]){
			ans+=x;
		}
		t+=x;
		w-=x;
		if(t>c[f]){
			f++;
		}
		if(w<=c[k]){
			k--;
		}
	}
	cout<<ans;
}