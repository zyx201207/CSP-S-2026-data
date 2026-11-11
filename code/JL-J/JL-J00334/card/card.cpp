#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],mx[N],sum[N],ans[N],lts[N];
vector<int> seg[N],s[N];
int check(int l,int r){
	int mid=0,ans=0;
	while(l<=r){
		mid=((l+r)>>1);
		if(sum[mid]-sum[l-1]>0) r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],s[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		int len=s[a[i]].size();
		int l=mx[i],r=len-1,mid;
		while(l<=r){
			mid=((l+r)>>1);
			if(s[a[i]][mid]>=i) r=mid-1;
			else l=mid+1;
		}
		mx[i]=mid;
		for(int j=mid;j<len;j++){
			if(i==s[a[i]][j]) continue;
			seg[i].push_back(s[a[i]][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int ls=seg[i].size();
		sum[i]=sum[i-1]+ls;
	}
	for(int i=1;i<=n;i++){
		int lst=i,ls=check(lst,n);
		while(ls!=0){
			int len=seg[ls].size()-1;
			int nw=seg[ls][len];
			for(int k=lst;k<=ls;k++) lts[a[k]]=ans[a[k]];
			for(int k=lst;k<=ls;k++) if(lts[a[k]]==ans[a[k]]) ans[a[k]]++;
			lst=nw+1;
			ls=check(lst,n);
		}
		if(lst<=n){
			for(int k=lst;k<=n;k++) lts[a[k]]=ans[a[k]];
			for(int k=lst;k<=n;k++) if(lts[a[k]]==ans[a[k]]) ans[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
