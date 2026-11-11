#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n,m,a[N],ans[N],dist[N],last[N],st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(last[a[i]]==0) last[a[i]]=i;
		else dist[last[a[i]]]=i-last[a[i]],last[a[i]]=i;
	}
	for(int l=1;l<=n;l++){
		int t=l;
		while(t<=n){
			if(dist[t]>0) t+=dist[t];
			else ans[a[t]]++,t++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

