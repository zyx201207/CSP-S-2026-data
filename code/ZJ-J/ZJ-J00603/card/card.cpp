#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;
const int N=5e5+5;
int net[N],pre[N];
int a[N];
int ans[N];
int dis[N];
int n,m;
signed main(void){
	IOS;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        net[i]=i+1;
        dis[i]=1;
    }
    for(int i=n;i>=1;i--){
        if(pre[a[i]])net[i]=pre[a[i]];
        pre[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dis[net[i]]+=dis[i];
        ans[a[i]]=max(ans[a[i]],dis[i]);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i<m)cout<<" ";
    }
    cout<<endl;
	return 0;
}
