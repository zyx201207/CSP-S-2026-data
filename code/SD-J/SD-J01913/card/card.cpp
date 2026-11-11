#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int cnt[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=0;k<n;k++){
		int t=1;
		int b[1005]={0};
        bool f[1005]={0};
        int c[1005]={0};
		for(int i=k+1;i<=n;i++){
			if(f[a[i]]==0) {
				t++;
				b[t]=a[i];
				
				c[a[i]]=t;
				f[a[i]]=1;
			}
			if(f[a[i]]==1){
				int x=c[a[i]];//这个数最左侧的坐标 
				for(int j=x+1;j<=t;j++) f[b[j]]=0;
				t=x;
			}
		}
		for(int j=1;j<=t;j++){
			cnt[b[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
