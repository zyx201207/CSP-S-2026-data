#include<bits/stdc++.h>

using namespace std;



ifstream fin("hub.in");

ofstream fout("hub.out");

#define cin fin

#define cout fout



using i64=long long;



const int N=1e5+5;



int n,k;

vector<int> E[N];



namespace A{

    #define bit(x) (1<<x>>1)

    int col[12],dis[12];

    void prt(int u){

        col[u]=2;

        for(int v:E[u]) if(col[v]==1) prt(v);

    }

    void main(){

        int U=(1<<n)-1;

        int ans=n;

        for(int s=3;s<=U;++s){

            if(__builtin_popcount(s)!=k) continue;

            memset(col,0,sizeof col);

            for(int i=1;i<=n;++i){

                if(bit(i)&s) col[i]=1;

				else col[i]=0;

                dis[i]=20;

            }

            int cnt=0;

            for(int i=1;i<=n&&cnt<=2;++i) if(col[i]==1){

                ++cnt;

                prt(i);

            } 

            if(cnt>2) continue;

            queue<pair<int,int>> q;

            for(int i=1;i<=n;++i) if(col[i]==2) q.push({i,0});

            int mx=0;

            while(!q.empty()){

                int u=q.front().first;

                int w=q.front().second;

                q.pop();

                if(dis[u]<=w) continue;

                dis[u]=w;

                mx=max(mx,w);

                for(int v:E[u]) if(dis[v]>w+1) q.push({v,w+1});

            }

            ans=min(ans,mx);

        }

        cout<<ans<<"\n";

    }

}



signed main(){

    int c,t;

    for(cin>>c>>t;t--;){

        cin>>n>>k;

        for(int i=1;i<=n;++i) E[i].clear();

        for(int i=1;i<n;++i){

            int u,v; cin>>u>>v;

            E[u].push_back(v);

            E[v].push_back(u);

        }

        if(c<=3) A::main();

    }

	return 0;

}



struct Code{

	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }

	~Code(){ fout.flush(),fin.close(),fout.close(); }

} wtl;

