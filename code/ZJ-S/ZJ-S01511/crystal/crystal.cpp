#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
vector<long long>v;
long long cnt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++){
		int p=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		cnt[p]++;
	}
	int len=v.size()-1;
	long long ans=0;
	long long res,la,costl,costr;
	for(int i=0;i<=len;i++){
		res=cnt[i];
		la=m;
		for(int j=i-1;j>=0&&la;j--){
			res+=min(la/(v[i]-v[j]),cnt[j]);
			la-=min(la/(v[i]-v[j]),cnt[j])*(v[i]-v[j]);
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
