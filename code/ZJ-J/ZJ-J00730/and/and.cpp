#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
bool no[200005];
int t[35];
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		for(int j = 32;j>=0;j--){
			if((a[i]>>j)&1ll)t[j]++;
		}
	}
	int ans = 0;
	for(int i = 32;i>=0;i--){
		if(t[i]>=m){
			ans+=1ll<<i;
			for(int j = 0;j<=32;j++)t[j] = 0;
			for(int j = 1;j<=n;j++){
				if(no[j])continue;
				if((a[j]>>i)&1ll){
					for(int k = 32;k>=0;k--){
						if((a[j]>>k)&1ll)t[k]++;
					}
				}else{
					no[j] = 1;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
