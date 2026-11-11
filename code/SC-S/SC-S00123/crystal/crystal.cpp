#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<long long>sj(n);
	vector<long long>qzh(n+1);
	qzh[0]=0;
	for(int i=0;i<n;i++){
		cin>>sj[i];
	}
	sort(sj.begin(),sj.end());
	for(int i=0;i<n;i++){
		qzh[i+1]=qzh[i]+sj[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		long long x=sj[i];
		int l=0,r=i;
		while(l<r){
			int mid=l+(r-l)/2;
			int s=i-mid+1;
			if(x*s-(qzh[i+1]-qzh[mid])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}