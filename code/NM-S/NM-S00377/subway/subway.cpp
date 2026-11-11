#include <bits/stdc++.h>
using namespace std;
long long x,n,m,c,d,q,w[500100],a[600],t[600],qd[100010],zd[100010],ans=INT_MAX;
void dfs(int k,int q,int z,long long tm){
    if(q==z){
        ans=min(ans,tm);
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[0]==q){
            dfs(k+1,a[1],z,tm+t[0]);
        }
        if(a[1]==q){
            dfs(k+1,a[0],z,tm+t[1]);
        }
    }
    return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=1;j<=x;j++){
        cin>>a[i]>>t[i];
        }
	}
	for(int i=1;i<=q;i++){
        cin>>qd[i]>>zd[i];
	}
	if(c>=7&&c<=11){
       for(int i=1;i<=q;i++)
        dfs(1,qd[i],zd[i],0);
        cout<<ans;
    }
	return 0;
}
