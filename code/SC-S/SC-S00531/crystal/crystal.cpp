#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int ma=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		vector<long long> v;
		for(int j=n;j>=1;j--){
			if(a[i]>=a[j]) v.push_back(a[i]-a[j]);
		}
		sort(v.begin(),v.end());
		int j=0;
		while(sum<=m&&j<v.size()){
			if(sum+v[j]>m){
				break;
			}
			sum+=v[j];
			j++;
		}
		ma=max(j,ma);
	}
	cout<<ma;
	return 0;
}