#include <bits/stdc++.h>
using namespace std;

int sum[30001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1],len[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int o=1;
		for(int j=i;j<=n;j++){
			bool b=1;
			for(int k=n;k>j;k--){
				if(a[k]==a[j]){
					j=k;
					o=k;
					sum[a[k]]++;
					b=0;
				}
			}
			if(b){
				sum[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i]<< ' ';
	}
}
