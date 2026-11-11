#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], ind[300005], d[500005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		memset(ind, 0, sizeof ind);
		memset(d, 0, sizeof d);
		int pos=1;
		for (int j=i;j<=n;j++){
			if (ind[a[j]]==0){
				ind[a[j]]=pos;
				d[pos++]=a[j];
			}
			else{
				int l=ind[a[j]], r=pos;
				for (int k=l;k<=r;k++){
					ind[d[k]]=0;
					d[k]=0;
				}
				pos=l;
				ind[a[j]]=pos;
				d[pos++]=a[j];
			}
		}
		for (int j=1;j<pos;j++){
			ans[d[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
