#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
ll n,m,a[200005],b[50],u[50],ans;
void load(ll x){
	int i=1;
	while(x>0){
		b[i]+=(x%2);
		i++;
		x=x>>1;
	}
	return ;
}
void find(int h){
	vector<int>e[50];
	for(int i=1;i<=n;i++){
		if((a[i]&u[h])==u[h]){
			e[h].push_back(i);
		}
	}
	for(int k=h-1;k>=1;k--){
		for(int i=0;i<e[k+1].size();i++){
			if((a[e[k+1][i]]&u[k])==u[k]){
				e[k].push_back(e[k+1][i]);
			}
		}
		if(e[k].size()<m){
			ans=a[e[k+1][0]];
			for(int i=1;i<m;i++)	ans=(ans&a[e[k+1][i]]);
			return ;
		}
	}
	ans=a[e[1][0]];
	for(int i=1;i<m;i++)	ans=(ans&a[e[1][i]]);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	u[1]=1;
	for(int i=2;i<=30;i++){
		u[i]=u[i-1]<<1;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		load(a[i]);
	}
	for(int i=30;i>=1;i--){
		if(b[i]>=m){
			find(i);
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2 3 15 12 12
*/
