#include<bits/stdc++.h>
using namespace std;
int n,m,ans,now;
vector<int>v[50];
int a[200005];
unordered_map<int,bool>f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++)if((1<<j)&a[i])v[j].push_back(a[i]);
	}
	for(int i=29;i>=0;i--){
		if((int)v[i].size()<m)continue;
		now=0;
		for(int j=0;j<(int)v[i].size();j++){
			if(!f[v[i][j]])now++;
		}
		if(now>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==0)f[a[j]]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
