#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long>v,mer;
struct N{
	int l,r;
};
long long merge_my(int l,int r){
	return mer[r]-(l-1)*(v[r]-v[l-1])-mer[l-1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	v.resize(n+1);
	mer.resize(n+1);
	mer[0]=0;
	v[0]=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	};
	sort(v.begin()+1,v.end());
	for(int i=1;i<=n;i++){
		mer[i]=(i-1)*(v[i]-v[i-1])+mer[i-1];
	}
	int k=1;
	int ans=1;
	for(int i=2;i<=n;i++){
		while(merge_my(k,i)>m){
			k++;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
} 