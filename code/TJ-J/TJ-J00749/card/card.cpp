#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//·¢ÈÈopen
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int a[50005];
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
 	int d[30005];
	for(int i = 1;i<=n;++i){
		int b[30005];
		int c[30005];
		for(int j = i;j<=n;++j){
			b[j] = a[j];
			if(c[b[j]] == 0){
				d[b[j]]++;
				c[b[j]]++;
			}else{
				int b[30005];
				b[j] = a[j];
				d[b[j]]-=c[b[j]];
				c[b[j]] = 0;
			}
		}
	}
	for(int j = 1;j<=m;++j){
		cout<<d[j]<<' ';
	}
	return 0;
}
