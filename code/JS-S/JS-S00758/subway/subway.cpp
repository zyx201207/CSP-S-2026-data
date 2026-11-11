#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m);
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    vector<vector<pair<int,int>>> mtr(n);
    vector<vector<pair<int,int>>> stn(m);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        mtr[i].resize(k);
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            mtr[i][j]=make_pair(a,t);
            stn[a].push_back(make_pair(j,t));
        }
    }


    /*if(12<=c&&c<=19){
        int s,t;
        cin>>s>>t;
        queue<pair<int,int>> q;
        q.push(s);
        vector<int> dist(n+m);
        while(!q.empty()){
            int cur=q.front();
            int u=cur.first,w=cur.second;
            q.pop();
            dist[u]=
            if(cur>=m){
                cur-=m;
                for(int i=0;i<mtr[c].size();i++){
                    q.push(mtr[c][i]);
                }
            }else{
            }

        }
        fclose(stdin);
        fclose(stdout);
        return 0;

    }*/

    while(q--){
        int s,t;
        cin>>s>>t;
        int ans=w[s]+w[t];
        //solve
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
