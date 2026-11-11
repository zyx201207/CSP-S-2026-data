#include<bits/stdc++.h>
#define LL long long int
using namespace std;
int a[500009];
int f[3009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			memset(f,0,sizeof f);
			for(int k=j;k<=n;k++){
				if(f[a[k]]==0){
					f[a[k]]=k;
				} else {
					for(int p=k;p>f[a[k]];p--){
						f[a[p]]=0;
					}
					f[a[k]]=k;
				}
			}
			if(f[i]!=0){
				ans++;
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}