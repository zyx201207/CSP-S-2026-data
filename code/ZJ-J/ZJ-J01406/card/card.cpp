#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int g[N],h[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	for(int k=1;k<=n;k++){
		memset(h,0,sizeof h);
		int last=k-1;
		for(int i=k;i<=n;i++){
			int l=last;
			while(g[i]!=h[l]&&l>k-1) l--;
			if(l!=k-1) last=l;
			else h[++last]=g[i];
		}
		for(int i=k;i<=last;i++) cnt[h[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
