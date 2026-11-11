#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,mx;
int a[N],ans[N];
vector<int> mp[40],mpp[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],tt=1;
		while(t){
			if((t&1)==1){
				mp[tt].push_back(i);
				mpp[i].push_back(tt);
			}
			tt++;
			t>>=1;
		}
		mx=max(tt,mx);
	}
	int x=0,sz=0;
	for(int i=mx+1;i>=1;i--){
		if(mp[i].size()>=m){
			x=i,sz=mp[i].size();
			for(int j=0;j<sz;j++){
				ans[j]=mp[i][j];
			}
			break;
		}
	}
	for(int i=1;i<=mx+1;i++) mp[i].clear();
	for(int j=0;j<sz;j++){
		for(int k:mpp[ans[j]]){
			if(k>x){
				break;
			}
			mp[k].push_back(ans[j]);
		}
	}
	for(int i=x-1;i>=1;i--){
		if(mp[i].size()>=m){
			sz=mp[i].size();
			for(int j=0;j<sz;j++){
				ans[j]=mp[i][j];
			}
			for(int j=1;j<=i;j++) mp[j].clear();
			for(int j=0;j<sz;j++){
				for(int k:mpp[ans[j]]){
					if(k>i){
						break;
					}
					mp[k].push_back(ans[j]);
				}
			}
		}
	}
	int aans=a[ans[0]];
	for(int i=1;i<sz;i++){
		aans=aans&a[ans[i]];
	}
	cout<<aans<<endl;
	return 0;
}
