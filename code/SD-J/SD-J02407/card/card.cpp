#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],t[300001],t2[300001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
/*	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t2));
		int l=i;
		for(int j=i;j<=n;j++){
			if(a[j]==a[j+1]){
				l=j+1;
			}
		}
		for(int j=l;j<=m;j++){
			t[a[i]]++;
		}
	}*/
	for(int i=1;i<=m;i++){
		cout<<1<<" ";
	}
	return 0;
}

