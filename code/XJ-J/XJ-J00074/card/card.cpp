#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],b[M],c[M];
signed main(){
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now=0;
	for(int i=n;i>=1;i--){
		b[++now]=a[i];
		for(int j=1;j<now;j++){
			if(b[now]==b[j]){
				now=j;
				break;
			}
		}
		for(int j=1;j<=now;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
