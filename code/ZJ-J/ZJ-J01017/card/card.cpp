#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
const int M=3e5+7;
int n,m;
ll a[N],cnt[M]={};
vector<ll>res;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		res.clear();
		map<ll,bool> vis;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(res.back()!=a[j]) res.pop_back();
			}
			vis[a[j]]=1;
		}
		for(int j=1;j<res.size();j++){
			cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
