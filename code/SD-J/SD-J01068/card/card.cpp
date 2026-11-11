#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[300005],c[500005],d[500005];
set<int>se; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		se.insert(a[i]);
		if(b[a[i]]!=0){
			cout<<'*';
			for(int j=i+1;j<=n;j++){
				b[a[j]]=0;
				if(a[j]==a[i]){
					break;
				}
			}
		}
		b[a[i]]++;
		for(int p:se){
			int u=p;
			if(b[u]!=0){
				d[u]++;
			}
		}
	}
	for(auto p:se){
		int u=p;
		cout<<d[u]<<' ';
	}
	return 0;
}
