/*
Xi'an Aerospace City No.1 High School
Senior Grade 1
ZHANG Aoyi
SN-S00640

CCF CSP-S 2026
2026.10.31 14:30-18:30

The High School Affiliated to SNU
R#01-S#47

Answer Disk: D

This is the source code of [T3]
*/
#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>q;
int c,t,n,d;
int x[2000086];
int ans=0;
int tong[5050];
int minn=1e9;
void dfs(int l,int r,int ju){
	if(l==r){
		tong[ju]++;
		minn=min(minn,ju);
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]>d) break;
		dfs(i,r,ju+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				minn=1e9; memset(tong,sizeof(tong),0);
				dfs(i,j,0);
				if(tong[minn]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


