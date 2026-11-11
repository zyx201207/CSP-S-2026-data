#include<bits/stdc++.h>
using namespace std;
int a[500010];
int f[300010];
int cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int fg=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]<a[i-1]){
			fg=1;
		}
		f[a[i]]=i;
	}
	if (fg==0){
		for (int i=1;i<=n;i++){
			if (a[i]>a[i-1] && i!=1){
				cout << i-1 << " "; 
			}
		}
		cout << n;
		return 0;
	}
	if (m==1){
		cout << n;
		return 0;
	}
	int ol=0;
	for (int i=1;i<=n;i++){
		ol=i;
		while (ol<=n){
			cnt[a[ol]]++;
			if (f[a[ol]]!=0){
				ol=f[a[ol]];
				ol++;
			}
			else{
				ol++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
