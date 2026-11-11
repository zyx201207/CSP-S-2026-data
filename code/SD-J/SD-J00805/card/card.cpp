#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+7;
int n,m;
int a[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int k=1;k<=n;k++){
		for (int p=k;p<=n;){
			cnt[a[p]]++;
			for (int j=n;j>=p;j--){
				if (a[j]==a[p]){
					p=j+1;
					break;
				}
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
