#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) if(cnt[j]!=0&&cnt[j]%2==1) sum[j]++; 
		cnt[a[i]]--;
	}
	for(int i=0;i<m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
