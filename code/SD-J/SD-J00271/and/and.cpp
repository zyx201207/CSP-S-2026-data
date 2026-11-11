#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],dp[2005][2005],mx;
bool b=true;
map<int,int> mp;
int find(int x){
	int le=1,ri=n;
	while(le<=ri){
		int mid=(le+ri)/2;
		if(a[mid]<x){
			le=mid+1;
		}else{
			ri=mid-1;
		}
	}
	if(a[le]<x){
		return -1;
	}
	return le;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int te=1;
	for(int i=1;i<=30;i++){
		te*=2;
		mp[te]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		dp[i][1]=mx;
		if(mp[a[i]+1]==0){
			b=false;
		}
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	if(m==2){
		int aa=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				aa=max(aa,a[i]&a[j]);
			}
		}
		cout<<aa<<endl;
		return 0;
	}
	if(mx<=4){
		sort(a+1,a+n+1);
		int k=find(4),kk=find(3),kkk=find(2),kkkk=find(3);
		if(n-k+1>=m){
			cout<<4;
		}else if(k-kk>=m){
			cout<<3;
		}else if(k-kkk>=m){
			cout<<2;
		}else if(kkk-kkkk+k-kk>=m){
			cout<<1;
		}
		return 0;
	}
	if(b){
		sort(a+1,a+n+1);
		int kk=a[n];
		for(int w=0;w<m;w++){
			kk=kk&a[n-w];
		}
		cout<<kk;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=min(m,i);j++){
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[n][m];
}
