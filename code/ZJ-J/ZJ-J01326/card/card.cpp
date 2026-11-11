#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],b[300005],chu[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int T=1;T<=n;T++){
		int wei=1,zhi[300005];
		for(int i=1;i<=m;i++){
			chu[i]=0;
			b[i]=0;
			zhi[i]=1e9;
		}
		for(int i=T;i<=n;i++){
			if(chu[a[i]]==1){
				if(zhi[a[i]]>=wei){
					zhi[a[i]]=wei;
					b[wei]=a[i];
				}
				else{
					if(i<n){
						wei=zhi[a[i]]+1;
					}
				}
			}
			else{
				b[wei]=a[i];
				chu[a[i]]=1;
				zhi[a[i]]=wei;
				if(i<n)wei++;
			}
		}
		for(int i=1;i<=wei;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
