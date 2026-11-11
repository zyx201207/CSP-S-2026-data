#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000010
long long w[MAXN],k[MAXN],a[10010][10010],t[10010][10010],x,y;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	//出得啥羁绊题 
	for(int i=0;i<q;i++){
		cin>>x>>y;
		long long ans=0;
		ans+=w[x-1]+w[y-1]+t[x][x];
		cout<<ans<<"\n";
	}
	return 0;
}






















/* 
题好难啊
谁出的
出题人 我阐述你的梦
*/ 
