#include<bits/stdc++.h>
using namespace std;
const int N=5e3+8,M=3e3+8;
int a[N],f[N][M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][a[j]]++;
			if(f[i][a[j]]==2){
				int o=a[j];
				for(int k=j-1;;k--){
					f[i][a[k]]--;
					if(a[k]==o){
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(f[j][i]>=1)++ans;
		}
		cout<<ans<<" ";
	}
	return 0;
}

