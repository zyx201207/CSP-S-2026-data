#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;

int c,T,n,len,a[N];
int f[N],cnt[N],t[N];

int solve1(){
	int rt=0;
	for(int s=1;s<=n;s++){
		for(int i=s-1;i<=n;i++)f[i]=cnt[i]=0;
		t[0]=1,cnt[s]=1,f[s]=0;
		for(int i=1;i<=n;i++)t[i]=0;
		for(int i=s+1,l=s;i<=n;i++){
			while(a[i]-a[l]>len&&l<i)t[f[l]]-=cnt[l],l++;
			f[i]=f[l]+1;
			cnt[i]=t[f[l]];
			t[f[i]]+=cnt[i];
			rt+=(cnt[i]==2);
		}
	}
	return rt;
}

void solve(){
	bool flaga=true;
	cin>>n>>len;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<n;i++)if(a[i]-a[i-1]!=a[i+1]-a[i])flaga=false;
	if(flaga){
		int sz=0;
		while(a[1+sz]-a[1]<=len&&sz+1<n)sz++;
		sz--;
		if(sz<=1)cout<<0<<'\n';
		else{
			sz=sz*2;
//			cout<<'!'<<len<<','<<a[2]-a[1]<<'!'<<'\n';
			if(sz>n)cout<<0<<'\n';
			else cout<<n-sz+1<<'\n';
		}
	}else if(c<=10)cout<<solve1()<<'\n';
	 
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
