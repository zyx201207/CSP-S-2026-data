#include<bits/stdc++.h>
using namespace std;
map<int,int> ma;

int main()
{
    
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int z=0;z<n;z++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int z=0;z<n;z++){
        map<int,bool> vis;
        vector<int> desk;
        for(int y=z;y<n;y++){
            if(!vis[y]){
                desk.push_back(y);
                vis[y]=true;
            }else{
                while(desk.back()!=y) desk.pop_back();
            }
        }
        for(int t:desk){
            ma[t]++;
        }
    }
    for(int z=0;z<m;z++) cout<<ma[z]<<' ';
    return 0;
}