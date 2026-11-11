#include<bits/stdc++.h>
using namespace std;
int n,m,sum[500100],cnt[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		sum[cnt[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
	//4 3 1 2 1 3
}
