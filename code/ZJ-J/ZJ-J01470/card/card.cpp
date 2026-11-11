
#include<bits/stdc++.h>
using namespace std;
int c[500010];
map<int,int>mp,ans;
int n,m,a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		mp.clear();
		int l=0;
		for(int i=t;i<=n;i++){
			if(mp[a[i]]>l||mp[a[i]]==0){
				l++;
				c[l]=a[i];
				mp[a[i]]=l;
			}
			else {
				l=mp[a[i]];
			}
		}
		for(int i=1;i<=l;i++){
			ans[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}