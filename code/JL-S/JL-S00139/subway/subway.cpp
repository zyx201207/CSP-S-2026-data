#include<bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
int arr[1005][1005];
int arr2[100005];
int arr3[100005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>arr2[i];
    }for(int i=1;i<=n;i++){
        int l;cin>>l;
        for(int x=1;x<=l;x++){
            int y,w;
            cin>>y>>w;
            arr3[y]+=w;
            arr[x][y]=arr[y][x]=w;
        }
    }while(q--){
        int ans=0;
        int x,y;cin>>x>>y;
        ans+=arr2[x]+arr2[y];
        for(int i=x;i<=y;i++){
            ans+=arr3[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
