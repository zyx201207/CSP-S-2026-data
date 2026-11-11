#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,maxx,b[500005],idx,ans,v;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
		maxx = max(a[i],maxx);
	}
	for(long long i = 1;i <= maxx;i++){
		idx = 0;
		v = 0;
		cnt = m;
		memset(b,0,sizeof b);
		for(long long j = 1;j <= n;j++){
			if(a[j] <= i){
				b[++idx] = a[j];
				
			}
		}
		sort(b+1,b+idx+1,cmp);
		while(cnt > 0){
			cnt -= (i - b[++v]);
			if(v == idx){
				break;
			}
		}
		ans = max(v,ans);
	}
	cout<<ans;
	return 0;
}
