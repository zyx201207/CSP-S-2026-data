

#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long ans[500005];
long long a[500005];
long long ne[500005];//dian 
long long pos[500005];// zhonglei
long long need[500005];
long long dpn[500005];
long long sp[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=n;i>=1;i--){
		if (pos[a[i]]){
			ne[i]=pos[a[i]];
		}
		pos[a[i]]=i;
	}
	for (int i=n;i>=1;i--){
		if (!ne[i]){
			if (i!=n){
				dpn[i]=i+1;
			}
			else{
				dpn[i]=0;
			}
			
			sp[i]=a[i];
		}
		else{

			dpn[i]=ne[i];
		}
		need[i]++;
	}
	for (int i=1;i<=n;i++){
		ans[sp[i]]+=need[i];
		need[dpn[i]]+=need[i];
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] ;
		if (i!=m){
			cout << " ";
		}
	}
	cout << '\n';
	return 0;
}

