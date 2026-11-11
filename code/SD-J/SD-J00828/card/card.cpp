#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005],tong[300005],dui[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=i;j<=n;j++){
			for(int h=1;h<=u;h++){
				if(dui[h]==a[j]){
					int c=u;
					for(int k=h;k<=c;k++){
						dui[k]=0;
						u--;
					}
					break;
				}
			}
			dui[++u]=a[j];
		}
		for(int j=1;j<=u;j++){
			tong[dui[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
