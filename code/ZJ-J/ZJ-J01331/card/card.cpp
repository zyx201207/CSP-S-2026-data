#include<bits/stdc++.h>
using namespace std;
long long n,m,num;
long long a[500005],l[300005],sum[500005],ans[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("carda.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		sum[l[a[i]]]++;
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>0){
			sum[l[a[i+1]]]+=sum[i];
			ans[a[i]]=sum[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

