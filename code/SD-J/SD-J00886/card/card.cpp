#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[N],l[N],f[M],minn=1e9;
long long cnt[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(f[a[i]]){
			minn=min(minn,f[a[i]]);
			l[i]=l[minn];
		}
		else{
			l[i]=i;
		}
		f[a[i]]=i;
		ans[l[i]]++;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=ans[i];
		cnt[a[i]]+=sum;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;	
}
