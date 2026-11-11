#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[200010];
int a[200010];
int ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int q=0;
	for(int j=1;j<=n;j++){
		for(int l=1;l<=n;l++){
			a[l]=0;
		}
		for(int i=j;i<=n;i++){
			for(int e=1;e<=n;e++){
				if(a[e]==p[i]){
					q=e;
					for(int u=e;u<=n;u++){
						a[u]=0;
					}
					break;
				}
			}
			q++;
			a[q]=p[i];
			for(int x=1;x<=m;x++){
				for(int y=1;y<=n;y++){
					if(a[y]==x){
						ans[x]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	} 
}
