#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
struct node{
    long long fir,las;
};
map <long long,node> ma;
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(ma.find(a[i])==ma.end()) ma[a[i]].fir=i;
        ma[a[i]].las=i;
    }
    for(int i=1;i<=n;i++){
        long long pos=i;
        while(pos<=n){
            if(!vis[a[pos]]) vis[a[pos]]=true;
            if(pos!=ma[a[pos]].las&&ma[a[pos]].fir!=ma[a[pos]].las) pos=ma[a[pos]].las;
            else pos++;
        }
        for(int i=1;i<=m;i++){
        	if(vis[i]){
        		ans[i]++;
        		vis[i]=false;
			}
		}
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
