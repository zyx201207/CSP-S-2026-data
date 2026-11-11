#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],cnt,ans,nxt[200002],pre[200002],hd,tl;
int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m,hd=1,tl=n+1;
	for(int i=1;i<=n;i++)cin>>a[i],nxt[i]=i+1;
	for(int i=2;i<=n+1;i++)pre[i]=i-1;
	for(int i=29;i>=0;i--){
		cnt=0;
		for(int j=hd;j!=tl;j=nxt[j])cnt+=(a[j]>>i&1);
		if(cnt>=m){
			ans|=(1<<i);
			for(auto j=hd;j!=tl;j=nxt[j]){
				if(!(a[j]>>i&1)){
					if(j==hd)hd=nxt[j];
					else if(nxt[j]==tl){
						tl=j;
						break;
					}
					else nxt[pre[j]]=nxt[j],pre[nxt[j]]=pre[j];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
