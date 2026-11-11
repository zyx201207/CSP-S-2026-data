#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],f[300005],df[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			b[j]=a[j];
		}
		memset(f,0,sizeof f);
		for(ll j=i;j<=n;j++){
			if(f[b[j]]!=0){
				for(ll k=j-1;k>=i;k--){
					if(b[k]!=b[j]){
						f[b[k]]--;
						b[k]=0;
					}else{
						b[k]=0;
						break;
					}
				}
			}else{
				f[b[j]]++;
			}
		}
		for(ll j=1;j<=m;j++){
			if(f[j]==1){
				df[j]++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<df[i]<<" ";
	}
	return 0;
}