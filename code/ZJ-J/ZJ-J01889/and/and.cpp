#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,res[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<(2<<n);i++){
		int ti=i,cnt=0;
		while(ti){
			if(ti&1){
				res[cnt+1]=a[cnt];
				cnt++;
			}
			ti>>=1;
		}
		if(cnt!=m)continue;
		long long sum=res[1];
		for(int i=2;i<=m;i++)sum&=res[i];
		ans=max(ans,sum);
	} 
	cout<<ans;
	return 0;
}
