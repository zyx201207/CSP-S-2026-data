#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=0,maxx2=0,flag,flag2,flag3;
void dfs(int pos,int geshu,long long sum){
	if(geshu==m){
		maxx=max(maxx,sum);
		return;
	}
	if(pos>n)return;
	if(geshu==0){
		dfs(pos+1,geshu+1,a[pos]);
		dfs(pos+1,geshu,0);
		return ;
	}
	dfs(pos+1,geshu+1,sum&a[pos]);
	dfs(pos+1,geshu,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=(1<<a[i])-1)flag=1;
		if(a[i]!=i-1)flag2=1;
		if(a[i]>=4)flag3=1;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			} 
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n-1){
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		for(int i=1;i<=n-1;i++){
			maxx2=maxx2&a[i];
		}
		cout<<max(maxx,maxx2);
		return 0;
	}
	else if(flag==0){
		cout<<a[n]; 
		return 0;
	}
	dfs(1,0,0);
	cout<<maxx;
	return 0;
}
