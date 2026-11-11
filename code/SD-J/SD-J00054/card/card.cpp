#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000001],lo[1000001];
int tong[100001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		lo[a[i]]=max(i,lo[a[i]]);
	}
	for(int i=n;i>=1;i--){
		int pos=i;
		while(n-pos+1){
			if(lo[a[pos]]==pos){
				tong[a[pos]]++;
				pos++;
			}
			else{
				tong[a[pos]]++;
				pos=lo[a[pos]]+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

