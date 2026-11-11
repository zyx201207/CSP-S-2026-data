#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,a[500010],desk[500010],r,c[500010],ans[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int s=1;s<=n;s++){
		memset(c,0,sizeof c);
		r=0;
		for(int i=s;i<=n;i++){
			if(c[a[i]]==1){
				while(desk[r]!=a[i]){
					c[desk[r]]--;
					desk[r]=0;r--;
				}
			}else{
				desk[++r]=a[i];
				c[a[i]]++;
			}
		}
		for(int i=1;i<=r;i++){
			ans[desk[i]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
