#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+5;
ll a[N],ans=0;
vector<ll> t[35];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;a[i]>>j;j++){
			if((a[i]>>j)&1) t[j].push_back(a[i]);
		}
	}
	for(int i=32;i>=0;i--){
		if(t[i].size()>=m){
			ans+=(1<<i);
			vector<ll> tmp[35];
			for(ll v : t[i]){
				for(int j=0;j<i;j++){
					if((v>>j)&1) tmp[j].push_back(v);
				}
			}
			for(int j=0;j<i;j++){
				t[j]=tmp[j];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
