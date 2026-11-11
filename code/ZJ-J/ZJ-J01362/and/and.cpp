#include<bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long ll;
ll n,m,v,ans;
vector<ll> v1;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v;
		v1.push_back(v);
	}
	sort(v1.begin(),v1.end(),cmp);
	ans=v1[0];
	for(int i=0;i<m;i++){
		ans=ans&v1[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
