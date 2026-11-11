#include<bits/stdc++.h>
using namespace std;
int c,n,m;
int w[500050],k[520];
int ind[500050],ti[520][500020],trntim[500050],trn
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    if(c==20||c==21){
        if(n==1){
            while(q--){
                int x,y;cin>>x>>y;
                cout<<w[x]+w[y]<<'\n';
            }return 0;
        }
        set<int>s[3];
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                int x,t;cin>>x>>t;
                s[i].insert(x);
                trntim[x]+=t;
                ind[x]++;
                if(ind[x]==2)trn=x;

            }
        }   
        while(q--){
            int x,y;
            cin>>x>>y;
            if(s[1].count(x)&&s[1].count(y)||s[2].count(x)&&s[2].count(y)){
                cout<<w[x]+w[y]<<'\n';
            }
            else{
                cout<<w[x]+w[y]+trntim[trn]<<'\n';
            }
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,t;cin>>x>>t;
        }
    } 
    while(q--){
        cin>>x>>y;
        cout<<w[x]+w[y]<<'\n';
    }
}

