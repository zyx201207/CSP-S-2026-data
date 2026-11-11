
#include <bits/stdc++.h>
#define int long long
#define INF 4000000000000000005
#define N 500005
using namespace std;
int c,n,m,d,q;
vector <vector<pair<int,int>>> st(m+1);
int w[N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
            cin>>w[i];

    }
    vector <vector<pair<int,int>>> st(m+1);
    vector <vector<int>> dd(n,vector<int>(n,INF));
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            st[a].push_back({i,t});

        }

    }
    for(int i=0;i<n;i++){
        dd[i][i]=0;

    }
    for(int j=1;j<=m;j++){
        auto& v=st[j];
        for(int p=0;p<v.size();p++){
            for(int r=p+1;r<v.size();r++){
                int cc=v[p].second+v[r].second;
                int aa=v[p].first;
                int bb=v[r].first;
                dd[aa][bb]=min(dd[aa][bb],cc);
                dd[bb][aa]=min(dd[bb][aa],cc);

            }
        }



    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(dd[i][k]>=INF/2){
                continue;
            }
            for(int j=0;j<n;j++){
                dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
            }
        }

    }
    for(int nnn=1;nnn<=q;nnn++){
        int x,y;
        cin>>x>>y;
        int best=INF;
        for(auto& [i,ti]:st[x]){
            for(auto& [k,tk]:st[y]){
                best=min(best,ti+dd[i][k]+tk);


            }

        }
        cout<<w[x]+w[y]+best<<'\n';
    }
    return 0;
}
