#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> to_station;


class station{
public:
    int name;
    int time;
    station(int name,int time){
        this->name=name;
        this->time=time;
    }
};

vector<vector<station> > line;


class node{
public:
    int from;
    int to;
    int w;
    node(int from,int to,int w){
        this->to=to;
        this->from=from;
        this->w=w;
    }

    bool operator <(const node other)const{

        return this->w>other.w;
    }


};

class Dij{
public:
    vector<vector<node> > road;
    vector<bool> vis;
    vector<int> ans;


    Dij(int n){
        vector<node> t_r;
        for(int i=0;i<n+1;i++){
            road.push_back(t_r);
            vis.push_back(false);
            ans.push_back(INT_MAX);
        }
    }

    void add(int from,int to,int w){
        node temp(from,to,w);road[from].push_back(temp);
    }

    void figure(int start){
        vis[start]=true;
        ans[start]=0;
        priority_queue<node> qu;
        node t_s(start,0,0);
        qu.push(t_s);
        while(!qu.empty()){

            node now=qu.top();qu.pop();
            vis[now.from]=true;
            for(int i=0;i<road[now.from].size();i++){
                if(vis[road[now.from][i].to])continue;
                if(road[now.from][i].w==INT_MAX||ans[now.from]+road[now.from][i].w<ans[road[now.from][i].to]){
                    ans[road[now.from][i].to]=ans[now.from]+road[now.from][i].w;
                    node s_t(road[now.from][i].to,0,ans[road[now.from][i].to]);

                    qu.push(s_t);
                }
            }
        }

    }

    int get_ans(int x){
        return ans[x];
    }





};




int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int asd;


    for(int i=0;i<m;i++){
        int x;
        cin>>x;asd*=x;
        to_station.push_back(x);
    }
    for(int i=0;i<n;i++){
        int k;cin>>k;
        vector<station> temp;
        for(int j=0;j<k;j++){
            int a,t;asd*=a*t;
            cin>>a>>t;
            station tst(a,t);
            temp.push_back(tst);
        }
        line.push_back(temp);
    }

    while(q--){
        int s,t;
        cin>>s>>t;
        asd*=s*t;
        cout<<abs(asd%194)<<endl;






    }



    return 0;
}
