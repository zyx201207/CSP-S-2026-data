#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],desk[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		int x=1;
		for(int i=q;i<=n;i++){
			int l;
			for(int j=x;j>=1;j--){
				if(desk[j]==a[i]){
					l=j;
					break;
				}
			}
			if(desk[l]==a[i]){
				x=l;
			}
			desk[x]=a[i];
			x++;
		}
		x--;
		for(int i=1;i<=x;i++){
			ans[desk[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 