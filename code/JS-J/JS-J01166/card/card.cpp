#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],laspos[500005],ans[500005],quan[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
    //cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        laspos[a[i]]=i;
        quan[i]=1;
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=quan[i];
        quan[laspos[a[i]]+1]+=quan[i];
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
       // cout<<ans[i]<<" ";
    }
    //cout<<"\n";
	return 0;
}
