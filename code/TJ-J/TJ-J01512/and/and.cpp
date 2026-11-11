#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
map<int,int>mp[32];
int ans;
int r;
int i;
int ef(int x,int y){
	int xx=x;
	int cnt=0;
	while(xx!=0){
		if(xx&1){
			mp[cnt][x]=1;
		}
		xx>>=1;
		cnt++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		ef(a[i],i);
	}
	r=n;
	for(i=29;i>=0;i--){
		int nw=0;
		for(int j=1;j<=r;j++){
			if(mp[i][a[j]]==1){
				a[++nw]=a[j];
			}
		}
		if(nw>=m){
			r=nw;
			ans+=(1<<i);
		}
		if(r<m){
			break;
		}
	}
	cout<<ans; 
}
