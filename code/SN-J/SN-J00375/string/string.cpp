#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char b[200005];
pair<int,int> st[200005];
vector<pair<int,int>> e[35];
int x[200005],y[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		st[i]={num+1,b[i]-'a'+1};
		num+=a[i];
	}
	st[n+1]={1e18,0};
	int k=(num+1)/2;
	for(int i=1;i<=n;i++){
		int sy=st[i].first;
		if(sy<=k&&st[i+1].first>k){
			e[b[i]-'a'+1].push_back({sy,k});
			e[b[i]-'a'+1].push_back({k+1,sy+a[i]-1});
		} 
		else e[b[i]-'a'+1].push_back({sy,sy+a[i]-1});
	}
	int ans=0;
	for(int i=1;i<=26;i++){
		int sz=e[i].size();
		for(int j=0;j<e[i].size();j++){
			x[j]=e[i][j].first;
			y[j]=e[i][j].second;
		}
		for(auto id:e[i]){
			int l=id.first,r=id.second;
			if(l>k){
				int rf=num-l+1,lf=num-r+1;
				int lbj=lower_bound(y,y+sz,lf)-y;
				int rbj=upper_bound(x,x+sz,rf)-x;
				for(int j=lbj;j<rbj;j++){
					ans+=max(0ll,(min(y[j],rf)-max(x[j],lf)+1));
				}
			}
		}
	}
	cout<<(num-k)-ans;
}
