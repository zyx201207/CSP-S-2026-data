#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		vector<int>v(m+1);
		unordered_map<int,int>mp,c;
		for(int i=j;i<=n;i++){
			v.push_back(a[i]);
			if(mp.count(a[i])){
				for(int k=mp[a[i]];k<i;k++){
					c[a[k]]++;
				}
				mp[a[i]]=i;
			}else mp[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cnt[v[i]]++;
			cnt[v[i]]-=c[v[i]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
