#include<bits/stdc++.h>
using namespace std;

//CCF are handsome!
//Please give me more score!
//rp++!
//FULL MARK PLEASE!

inline bool cmp(long long x,long long y){
	return x>y;
}

long long n,m,a[200005],b[200005],idx,ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	int maxk=30;
	while(1){
		maxk--;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]&(1ll<<maxk)) cnt++;
		}
		if(cnt>=m) break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]&(1ll<<maxk)){
			++idx;
			for(int j=maxk;j>=0;j--)
				if(a[i]&(1ll<<j)) b[idx]|=(1ll<<j);
		}
	}
//	for(int i=1;i<=idx;i++) printf("%d ",b[i]);
	sort(b+1,b+idx+1,cmp);
	ans=b[1];
	for(int i=1;i<=m;i++){
		ans&=b[i];
	}
	printf("%lld",ans);
	return 0;
}
