#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int b[300005],nxt[N];
int ans[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		nxt[i]=b[a[i]];
		if(b[a[i]]==0)b[a[i]]=i;
	}
	for(int l=1;l<=n;l++){
		int st=l;
		while(st<=n){
			while(nxt[st]==0&&st<=n){
			    ans[a[st]]++;
			    st++;
	    	}
	    	while(nxt[st]!=0){
	    		st=nxt[st];
	    	}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
