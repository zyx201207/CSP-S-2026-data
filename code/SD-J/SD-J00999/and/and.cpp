#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,wei[40],maxn,num,ch[200010];
vector<long long> ve[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1){
				wei[j]++;
				ve[j].push_back(i);
			}
		}
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	for(int i=30;i>=0;i--){
		if(wei[i]<=1)continue;
		if(ve[i].size()<m)continue;
		int sum=0;
		for(int j=0;j<ve[i].size();j++){
			int y=ve[i][j];
			if(ch[y]==num){
				ch[y]++;
				sum++;
			}
		}
		if(sum<m)continue;
		ans+=(1ll<<i);
		num++;
	}
	cout<<ans;
	return 0;
}
