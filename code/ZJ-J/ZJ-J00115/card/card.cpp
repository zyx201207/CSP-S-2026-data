#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],cnt[300005],maxa=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		vector<long long>v;
		long long cnt2[1005];
		memset(cnt2,0,sizeof cnt2);
		v.clear();
		for(long long k=i;k<=n;k++){
			for(long long j=0;j<v.size();j++){
				if(v[j]==a[k]){
					for(long long l=1;l<=v.size()-j;l++) v.pop_back();
				}
			}
			v.push_back(a[k]);
		}
		for(auto it:v){
			cnt2[it]=1;
		}
		for(long long i=1;i<=m;i++) cnt[i]+=(long long)cnt2[i]; 
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
