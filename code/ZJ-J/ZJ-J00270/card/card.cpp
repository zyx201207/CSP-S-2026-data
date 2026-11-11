#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int ans[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int h[10001]={0};
		for(int j=i;j<=n;j++){
			h[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(h[a[j]]>1){
				h[a[j]]--;
				int k=j+1;
				while(a[j]!=a[k]){
					h[a[k]]--;
					k++;
				}
				j=k-1;
			}
			else {
				ans[a[j]]++;
			}
		}
	}
	cout<<ans[1];
	for(int i=2;i<=m;i++){
		cout<<' '<<ans[i];
	}
	return 0;
}
