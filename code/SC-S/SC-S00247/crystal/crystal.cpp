#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],tot,x,ans,lim,val,cnt,t;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i]; 
	}
	if(n>=1e4){
		sort(a+1,a+n+1,cmp);
		ans=1;
		for(int i=2;i<=n;i++){
			val=a[1]-a[i];
			if(m-val<0) break;
			m-=val;
			ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	
	x=tot/n;
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		if(a[i]<x&&a[i+1]>=x) lim=i;
	}
	
	for(int pos=lim;pos<=n;pos++){
		cnt=0,t=m;
		for(int i=pos;i>=1;i--){
			val=a[pos]-a[i];
			if(t-val<0) break;
			cnt++;
			t=t-val;
		}
		ans=max(ans,cnt);
	}
	
	cout<<ans<<'\n';
	return 0;
}