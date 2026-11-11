#include<bits/stdc++.h>
using namespace std;
const int MX=(1e5+5)*5;
int n,m;
int a[MX],ans[MX],b[MX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=0;
	}
	
	for(int i=1;i<=n;i++){
		int v=1;
		for(int j=i;j<=n;j++){
			for(int l=i;l<v;l++){
				if(a[l]==a[j]){
					v=l;
					break;
				}
			}
			b[v]=a[j];
			v++;
		}
		for(int j=1;j<v;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}