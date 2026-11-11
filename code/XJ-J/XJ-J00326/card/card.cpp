#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],yun[N],xb=1,tong[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int t=1;t<=n;t++){
		xb=1;
		memset(yun,0,sizeof yun);
		for(int i=t;i<=n;i++){
			yun[xb++]=a[i];
			for(int j=1;j<xb;j++){
				if(yun[j]==a[i]){
					for(int z=j;z<xb-1;z++){
						yun[z]=0;
					}
					break;
				}
			}
		}
		for(int i=1;i<xb;i++) tong[yun[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<tong[i]<<' '; 
	return 0;
}
