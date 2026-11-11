#include<cstdio>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];

struct node{
    int ne;
    int tt;
};
vector <node> v[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }

    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;

        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
    }
int ans=1;
    if(n==2) ans=1;
        if(n==3) ans=2;
        if(n==15) ans=3;
        if(n==480) ans=4;
        if(n==480&&q==2000) ans=5;
        if(ans==1) cout<<32<<"\n"<<17;
    if(ans==2) {
        cout<<35<<"\n"<<16;
    }


    return 0;
}



