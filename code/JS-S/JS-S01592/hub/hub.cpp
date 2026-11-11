#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>p[200001];
int a(int nw,int fa,int pp){
    int minn=INT_MAX,ans=0;
    for(int i=0;i<p[nw].size();i++){
        if(nw==1&&fa==0){
            ans+=a(p[nw][i],nw,pp+1);
        }
        else if(nw!=fa){
            minn=min(minn,a(p[nw][i],nw,pp+1));
        }
    }
    if(ans!=0)return ans;
    return pp;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            p[x].push_back(y);
        }
        cout<<a(1,0,0)/(k*2);
    }
    return 0;
}
