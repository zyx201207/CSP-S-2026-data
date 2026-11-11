#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+6;
int n,ans=0;
ll m,a[MAXN],s[MAXN],sum=0;

void work1(){
	for(int i=1;i<=n;++i)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int l=1;l<=n;++l){
		for(int r=n;r>=l+1;--r){
			if(a[r]*(r-l+1)-s[r]+s[l-1]>m) continue;
			int tmp=r-l+1;
			for(int k=r+1;k<=n;++k){
				if(a[k]>a[r]) break;
				tmp++;
			}
			if(!ans) ans=tmp;
			else ans=max(ans,tmp);	
		}
	}
	cout<<ans<<'\n'; 
} 

void work2(){
	for(int i=1;i<=n;++i)	cin>>a[i];
	ll d=a[2]-a[1];
	for(int i=n-1;i>=0;--i){
		int tmp=(1+i)*i/2;
		if(tmp*d<=m){
			ans=i;
			break;
		}
	}
	cout<<ans+1<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000) work1();
	else work2();
	return 0;
}
