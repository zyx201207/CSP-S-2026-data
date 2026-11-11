#include<bits/stdc++.h>
using namespace std;
int a[10000];
int vis[1000][1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> x(5010);
		int w=0;
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(vis[i][k]){
				int ww=0;
				for(int s=1;s<=w;s++)
					if(a[s]==k) {ww=s;break;}
				for(int s=ww;s<=w;s++) vis[i][a[s]]--;
				w=ww-1;
			}
			w++;
			x[w]=k;
			vis[i][k]++;
		}
	}
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(vis[j][i]) sum++;
		}
		cout<<sum<<" ";
	}
	return 0;
}
