#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[300005];
	int pf[200005];
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		pf[i]=a[i];
	}
	bool tpf=true;
	sort(pf+1,pf+n+1);
	for (int i=1;i<=n;i++){
		if (pf[i]!=a[i]){
			bool tpf=false;
		}
	}
	long long ans=0;
	if (tpf){
		for (int i=1;i<=m;i++){
			ans=0;
			for (int j=i;j<=n;j++){
				if (i==a[j]){
					ans++;
				}
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}