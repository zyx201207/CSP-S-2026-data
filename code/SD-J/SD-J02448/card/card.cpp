#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q[500005],tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		int idx=0;
		for(int i=k;i<=n;i++){
			for(int j=1;j<=idx;j++){
				if(q[j]==a[i]){
					idx=j-1;
				}
			}
			q[++idx]=a[i];
		}
		while(idx){
			tong[q[idx]]++;
			idx--; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
} 
