#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],t[M];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],t[a[i]]=i;
	for(int i=1;i<=n;i++){
		int j=t[a[i]];
		bool f[M]={};
		while(j<=n){
			if(!f[a[j]]) mp[a[j]]++;
			f[a[j]]=true;
			if(j==t[a[j]]) j++;
			else j=t[a[j]];
		}
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
	return 0;
}
