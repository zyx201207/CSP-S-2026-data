#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int k=1;k<=n;k++){
		int top=1;
		int g[500005]={0};
		for (int i=k;i<=n;i++){
			g[top]=a[i];
			bool iff=false;
			for (int j=1;j<=top;j++){
				if (g[j]==a[i]){
					for (int c=j+1;c<=top;c++){
						g[c]=0;
					}
					top=j+1;
					iff=true;
					break;
				}
			}
			if (iff) continue;
			else top++;
		}
		for (int h=1;h<=m;h++){
			for (int hh=1;hh<=top-1;hh++){
				if (g[hh]==h){
					ans[h]++;
					break;
				}
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
