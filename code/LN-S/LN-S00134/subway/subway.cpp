#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
bool has(vector<int> a,int b){
    for(int i=0;i<a.size();i++){
        if(a[i]==b) return true;
    }
    return false;
}
int min(vector<int> a){
    int ans=INF;
    for(int i=0;i<a.size();i++){
        ans=min(ans,a[i]);
    }
    return ans;
}
vector<int> both(vector<int> a,vector<int> b){
    vector<int> ans;
    for(int i=0;i<min(a.size(),b.size());i++){
        if(has(a,b[i])) ans.push_back(b[i]);
    }
    return ans;
}
int loc(vector<int> a,int b){
    for(int i=0;i<a.size();i++){
        if(a[i]==b) return i;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    vector<vector<int>> mp;
    vector<vector<int>> to;
    vector<int> w;
    vector<vector<int>> sta;
    vector<vector<int>> a;
    vector<vector<int>> t;
    vector<int> s;
    vector<int> e;
    for(int i=1;i<=m;i++){
        int tmp;
        cin>>tmp;
        w.push_back(tmp);
    }
    a.resize(n+1);
    t.resize(n+1);
    mp.resize(n+1);
    to.resize(n+1);
    sta.resize(n+1);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            a[i].push_back(tmp1);
            t[i].push_back(tmp2);
            mp[tmp1].push_back(tmp2);
            mp[tmp2].push_back(tmp1);
            sta[tmp1].push_back(i);
            sta[tmp2].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size()-1;j++){
            to[j][j+1]=0;
            to[j+1][j]=0;
            for(int k=0;k<mp[j].size();k++){
                if(!has(sta[mp[j][k]],i)){
                    for(int l=0;l<sta[j].size();l++)
                        to[j][mp[j][k]]=min(t[sta[j][l]][loc(a[sta[j][l]],j)]+t[both(sta[j],sta[mp[j][k]])[0]][loc(a[sta[j][l]],j)],to[j][mp[j][k]]);
                }
            }
        }
    }
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        s.push_back(x);
        e.push_back(y);
    }
    for(int i=0;i<p;i++){
        vector<int> time;
        time.resize(n+1,INF);
        queue<int> que;
        que.push(s[i]);
        time[s[i]]=0;
        while(!que.empty()){
            int tmp;
            tmp=que.front();
            que.pop();
            for(int j=0;j<mp[tmp].size();j++){
                if(time[mp[tmp][j]]>time[tmp]+to[tmp][mp[tmp][j]]){
                    que.push(mp[tmp][j]);
                    time[mp[tmp][j]]=min(time[mp[tmp][j]],time[tmp]+to[tmp][mp[tmp][j]]);
                }
            }
        }
        cout<<(w[s[i]]+t[sta[s[i]][0]][loc(a[sta[s[i]][0]],s[i])]+w[e[i]]+t[sta[e[i]][0]][loc(a[sta[e[i]][0]],e[i])]+time[e[i]])<<endl;
    }



    return 0;
}
