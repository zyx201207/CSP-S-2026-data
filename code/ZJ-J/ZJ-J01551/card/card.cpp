#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],lst[300005],sum[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		lst[a[i]]=i;
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(lst[a[i]]!=i){
			continue;
		}
		if(lst[a[i]]!=n){
			sum[a[lst[a[i+1]]]]+=sum[a[i]];
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
