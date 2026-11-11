#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5,M=3e5+5;

int n,m;
int a[N];
int b[N];
int ans[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]) flag=1;
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int nj=1;nj<=n;nj++){
		int ix=0;
		map<int,int> mp;
		for(int i=nj;i<=n;i++){			
			if(mp.count(a[i])){
				ix=mp[a[i]]-1;
				set<int> s;
				for(auto it:mp){
					if(it.second>ix+1) s.insert(it.first);
				}
				for(auto it:s){
					mp.erase(it);
				}
			}
			b[++ix]=a[i];
			mp[a[i]]=ix;
		}
		for(int i=1;i<=ix;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
