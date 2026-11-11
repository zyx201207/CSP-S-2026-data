#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
vector<int> p(500005);
int cnt[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=sum;k++){
				if(p[k]==a[j]){
					sum=k-1;
					break;
				}
			}
			sum++;
			p[sum]=a[j];
		}
		for(int i=1;i<=sum;i++){
			cnt[p[i]]++;
		}
		p.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
