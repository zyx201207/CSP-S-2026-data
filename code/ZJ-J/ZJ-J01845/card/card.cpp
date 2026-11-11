#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int ans[300010];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int f[300010];
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			f[i]=-1;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=-1){
				for(int k=f[a[j]];k<=j;k++){
					f[a[k]]=-1;
				}
			}
			f[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=-1){
				ans[a[j]]++;
				f[a[j]]=-1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

