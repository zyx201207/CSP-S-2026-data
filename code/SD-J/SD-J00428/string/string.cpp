#include<iostream>
#include<cstdio>
#define int long long
//#define const 998244353
using namespace std;
pair<int,char>pir[200010];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pir[i].first>>pir[i].second;
	}
	int l=1,r=n;
	while(l<r){
		if(pir[l].first==pir[r].first){
			if(pir[l].second!=pir[r].second)ans+=pir[l].first;
			l++;r--;
		}else if(pir[l].first>pir[r].first){
			if(pir[l].second!=pir[r].second)ans+=pir[r].first;
			pir[l].first-=pir[r].first;
			r--;
		}else{
			if(pir[l].second!=pir[r].second)ans+=pir[l].first;
			pir[r].first-=pir[l].first;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
