#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5*1e5+7,M=3*1e5+7;
int a[N];
bool vis[M];
long long cnt[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[j]=0;
        }
        for(int j=i;j<=n;j++){
            v.push_back(a[j]);
            if(vis[a[j]]==1){
                for(int k=0;k<v.size();k++){
                    vis[a[k]]=0;
                }
                v.clear();
                v.push_back(a[j]);
            }
            vis[a[j]]=1;
        }
        for(int j=0;j<v.size();j++){
            cnt[v[j]]++;
            //cout<<v[j]<<" ";
        }
        v.clear();
        //cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
