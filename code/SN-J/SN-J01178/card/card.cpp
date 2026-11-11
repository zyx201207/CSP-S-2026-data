#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
int a[N],ans[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans[a[n]]=n;
	for(int i=1;i<=n;i++){
		for(int x=i;x<=n;x++){
			b[x]=a[x];
		}
		for(int left=i;left<=n;left++){
			for(int right=left+1;right<=n;right++){
				if(a[right]==a[left]){
					int h=right-left;
					for(int j=right;j<=n;j++){
						b[j-h]=b[j];
						for(int z=n-h;z<=n;z++){
							b[z]=0;
						}
					}
				} 
			}
		}
		for(int x=i;x<n;x++){
			ans[b[x]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
}
