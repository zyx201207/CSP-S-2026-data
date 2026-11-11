#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
const int N=5e5+10;
ll a[N],ans[N];
ll k[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(k,0,sizeof k);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int l=1;
			while(k[l]>=0){
				if (k[l]==a[j]){
					for (int r=l;r<=n;r++){
						k[r]=0;
						now=l;
					}
				}
				l++;
			}
			k[now]=a[j];
		}
		int j=1;
		while(k[j]>=0){
			ans[k[j++]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
