#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
unsigned int a[N];
bool v[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	bool b=0;
	for(ll j=30;j>=0;j--){
		vector<int> ve;
		for(int i=1;i<=n;i++){
			int x=((a[i]>>j)&1);
			if(x==1 && (b==0 || v[i]==1)) ve.push_back(i);
		}
		if(ve.size()>=m && b==0){
			b=1;
			for(int i=0;i<ve.size();i++) v[ve[i]]=1;
			ans+=(1ll<<j);
		} else if(ve.size()>=m){
			ans+=(1ll<<j);
			for(int i=1;i<=n;i++) v[i]=0;
			for(int i=0;i<ve.size();i++) v[ve[i]]=1;
		}
	}
	cout<<ans;
	return 0;
}