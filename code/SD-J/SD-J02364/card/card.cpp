#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],ans[300005],w[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		memset(w,0,sizeof(w));
		for(long long j=i;j<n;j++){
			w[a[j]]++;
		}
		for(long long j=1;j<=m;j++){
			if(w[j]%2==1){
				ans[j]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
