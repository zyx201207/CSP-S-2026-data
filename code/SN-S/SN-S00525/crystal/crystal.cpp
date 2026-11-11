//高子懿 SN-S00525 延安市安塞区初级中学
#include<bits/stdc++.h>
using namespace std;
long long sum[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n),ans(n);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long sum1=v[i]-v[j];
			if(sum1>=0 and sum1<=m){
				sum[i]+=sum1;
				ans[i]++;
			}
		}
	}
	int maxans=-100000;
	for(int i=1;i<=n;i++){	
		if(sum[i]==m){
			maxans=max(ans[i],maxans);
		}
	}
	cout<<maxans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
