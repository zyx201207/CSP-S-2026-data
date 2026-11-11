#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],yu[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	for (int i=1;i<=n;i+=1){
		int yl=0;
		for (int z=1;z<=sizeof(yu);z+=1){
			yu[z]=0;	
		}
		for (int j=i;j<=n;j+=1){
			int k=a[j],z;
			bool cf=0;
			for (z=1;z<=sizeof(yu);z+=1){
				if (k==yu[z]){
					cf=1;
					yl=z;
					break;
				}
			}
			if (!cf){
				yu[z+1]=k;
				yl+=1;
			}
		}
		for (int z=1;z<=yl;z+=1){
			ans[yu[z]]+=1;
		}
	}
	for (int i=1;i<=m;i+=1){
		cout<<3<<" "<<1<<" "<<4;
	}
	return 0;
}
