#include <bits/stdc++.h>
using namespace std;
int ans[500005],a[500005],st[500005];
bool f[500005];
int top;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		top=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<top;k++){
				if(st[k]==a[j]){
					top=k;
					break;
				}
			}
			st[top++]=a[j];
		}	
		for(int l=1;l<top;l++){
			if(!f[st[l]]){
				ans[st[l]]++;
				f[st[l]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}