#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],vis[200005],zui[200005];
long long mu[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		int l = 1;
		for(int j = i;j <= n;j++){
			if(vis[a[j]] == 1){
				while(mu[l] != a[j]){
					l--;
					vis[mu[l]] = 0;
					zui[mu[l]]--;
				}
				vis[mu[l]] = 1;
				zui[mu[l]]++;
				l++;
			}else{
				vis[a[j]] = 1;
				mu[l] = a[j];
				zui[mu[l]]++;
				l++;
			}
		}
		for(int j = 1;j <= m;j++){
			vis[j]= 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<zui[i]<<' ';
	}
    return 0;
}
