#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300006];
long long k[5000055];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(k,0,sizeof(k));
		int p=1;
		for(int j=i;j<=n;j++){
			bool q=0;
			int o=0;
			for(int l=1;l<=p;l++){
				if(k[l]==a[j]){
					q=1;
					o=l;
				}
				if(q==1)k[l]=0;
			}
			if(o!=0)p=o;
			k[p]=a[j];
			p++;
		}
		for(int j=1;j<=p;j++){
			ans[k[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
