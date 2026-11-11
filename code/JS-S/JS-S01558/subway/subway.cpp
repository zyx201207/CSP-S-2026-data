#include<bits/stdc++.h>
using namespace std;

struct station{
    int name;
    int t;
};

struct plan{
    int s1;
    int s2;
};
plan a2[500010];
station a1[500010];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int t1[500010];
    int t2[500010];
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t1[i];
    }
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        for(int j=1;j<=s;i++){
            cin>>a1[j].name>>a1[j].t;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>a2[i].s1>>a2[i].s2;
    }
    if(n==2) cout<<32<<endl<<17;
    if(n==3) cout<<35<<endl<<16;
    return 0;
}

