#include<bits/stdc++.h>

using namespace std;
int c,t;

int tb[1005][1005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            tb[x][y]=y;tb[y][x]=x;
        }cout<<(k+1)/2<<endl;
    }
    return 0;
}
