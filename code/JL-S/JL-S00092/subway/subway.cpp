#include<bits/stdc++.h>
using namespace std;
//#define int long long
bool b[503][503],b2[503][503];
int x[500003];
int c,n,m,d,q,al=0;
queue<int> qu;
int bfs(int no,int e){
    if(e==no){
        return 1;
    }
    for(int a=1;a<=n;a++){
        if(b[no][a]==1&&b2[no][a]==0){
            qu.push(a);
            b2[no][a]=1;
            b2[a][no]=1;
        }
        qu.pop();
    }
    return -1;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int a=0;a<m;a++){
        cin>>x[a];
    }
    int t;
    for(int a=0;a<n;a++){
        int k;
        cin>>k;
        int zan[500003];
        for(int s=0;s<k;s++){
            cin>>zan[s]>>t;
            for(int d=0;d<s;d++){
                b[x[s]][x[d]]=1;
                b[x[d]][x[s]]=1;
            }
        }
    }
    for(int a=0;a<q;a++){
        for(int s=0;s<n;s++){
            for(int d=0;d<n;d++){
                b2[s][d]=0;
            }
        }
        int be,en;
        cin>>be>>en;
        al=x[be-1]+x[en-1];
        while(qu.empty()==0){
            qu.pop();
        }
        qu.push(be);
        int ci=0;
        while(0<qu.size()){
            if(qu.front()==be){
                ci++;
                be=qu.front();
            }
            if(bfs(qu.front(),en)==1){
                cout<<al+t*2*ci;
                break;
            }
        }
    }
}
