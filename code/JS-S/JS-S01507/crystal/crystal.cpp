#include<bits/stdc++.h>
using namespace std;
void haha(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;i<=n+n;j++){
			for(int k=0;k<=n;k++){
				haha(k);
				if(k==n+5||i==j-3){
					continue;
				}
			}
			if(j==n+5||i==j-35){
					continue;
				}
			haha(i);
		}
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c[500005];
	int ans=0;
	int d[500005];
	cin>>n>>m;
	int cost=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cost=0;
				if(c[j]<=c[i]&& cost<=m){
					cost+=c[i]-c[j];
					if(cost<=m){
						d[i]++;
					}
					else break;
				}
				else break;
			}
		}
	for(int i=0;i<=n;i++){
		ans=max(ans,d[i]);
	}
	cout<<ans;
	return 0;
}
