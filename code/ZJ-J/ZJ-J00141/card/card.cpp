#include<bits/stdc++.h>
using namespace std;
int a[500005],f[300005],b[300005],ans[300005],z[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	bool fl=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			fl=1;
		}
		z[a[i]]=max(z[a[i]],i);
	}
	if(fl==0){
		for(int i=1;i<=m;i++) cout<<z[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			b[++cnt]=a[j];
			if(f[a[j]]!=0){
				for(int k=f[a[j]]+1;k<cnt;k++){
					f[b[k]]=0;
				}
				cnt=f[a[j]];
			}else{
				f[a[j]]=cnt;
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;	
		}
		for(int j=i;j<=n;j++){
			f[a[j]]=0;
		}	
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

