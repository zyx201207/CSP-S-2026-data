#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],ans,sum[32],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=0,s=a[i];
		while(s){
			if(s&1){
				sum[j]++;
			}
			s>>=1;
			j++;
		}
	}
	for(int k=30;k>=0;k--){
		if(sum[k]>=m){
			ans|=(1<<k);
			for(int i=1;i<=n;i++){
				if(a[i]&(1<<k) || vis[i]) continue;
				vis[i]=1;
				int j=0,s=a[i];
				while(s){
					if(s&1){
						sum[j]--;
					}
					s>>=1;
					j++;
				}
			}
		}
	}
	cout<<ans;
	
}
