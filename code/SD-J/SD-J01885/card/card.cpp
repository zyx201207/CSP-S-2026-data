#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,a[N],h[N];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500&&m<=200){
		int cnt=1;
		for(int i=1;i<=n;i++){
			cnt=0;
			memset(h,0,sizeof(h));
			for(int j=i;j<=n;j++){
				for(int k=1;k<=cnt;k++){
					if(h[k]==a[j]){
						for(int o=min(k,j);o<=max(k,j);o++){
							h[o]=0;
						}
					}
				}
				cnt++;
				h[cnt]=a[j];
			}
			for(int j=1;j<=cnt;j++){
				mp[h[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<mp[i]<<' ';
		}
	}
	else
	{
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]){
				cout<<i<<' ';
			}
		}
	}
	return 0;
}

