#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];bool f=1;
int cnt[300005];
int ans[300005];
int t[300005];
bool p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])f=0;
		t[a[i]]++;
	}
	if(f){
		for(int i=1;i<=m;i++){
			if(t[i]){
				t[i]+=t[i-1];
				cout<<t[i]<<" ";
			}
			else cout<<0<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt[j]=0;
			}
			int la=i,did=0;
			for(int j=i;j<=n;j++)p[j]=0;
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]){
					for(int k=cnt[a[j]];k<j;k++){
						cnt[a[k]]=0;
						p[k]=1;
					}
				}
				cnt[a[j]]=j;
			}
			for(int j=i;j<=n;j++){
				if(p[j]==0){
					ans[a[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1*/