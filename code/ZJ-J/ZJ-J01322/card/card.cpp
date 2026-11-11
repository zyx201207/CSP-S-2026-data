#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N];
int w[N];
int main(){
	freopen("card.int","r",stdin);
	freopen("card.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int r=i;
		int q[N]={0};
		for(int j=i;j<=n;j++){
			if(q[a[j]]==1){
				for(int k=j-1;k>=i;k--){
					if(a[j]==a[k]&&q[a[k]]==1){
						q[a[k]]=0;
						break;
					}
					q[a[k]]=0;
				}
				r=j;
			}
			q[a[j]]=1;
		}
		int e[N]={0};
		for(int j=1;j<=n;j++){
			if(e[a[j]]==0&&q[a[j]]==1) e[a[j]]++,w[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<w[i]<<" ";
	return 0;
}
