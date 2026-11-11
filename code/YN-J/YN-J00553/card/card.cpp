#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100,M=3e5+100;
int n,m,a[N],b[M],vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		if(vis[a[i]]==0)
			vis[a[i]]=i;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		int pos=0,last=i;
		while(last<=n){
			pos=vis[a[last]];
			last=pos+1;
			b[a[pos+1]]++;
			pos=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<' ';
	return 0;
}
