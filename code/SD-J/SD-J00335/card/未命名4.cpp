#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[i]==a[j]){
					for(int k=i;k<j;k++) cnt[i]--;
				}
			}
			cnt[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
