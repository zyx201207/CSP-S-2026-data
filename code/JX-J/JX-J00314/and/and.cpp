#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int m,n;
vector<int> v[N];
vector<int> ch2(int x){
    vector<int> k;
    k.assign(32,0);
    int l=0;
    while(x){
        k[l++]=x%2;
        x>>=1;
    }
    return k;
}
int ans[32];
bool f[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> g;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[i]=ch2(x);
        g.push_back(i);
    }
    for(int k=31;k>=0;k--){
        //int l=g.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!f[i]&&v[i][k])cnt++;
        }
        if(cnt<m){
            ans[k]=0;
            continue;
        }
        for(int i=0;i<n;i++){
            if(f[i])continue;
            if(v[i][k]==0){
                f[i]=1;
            }
        }
        ans[k]=1;
    }
    int l=31;
    while(!ans[l])l--;
    int x=0;
    for(int i=0;i<=l;i++){
        if(ans[i])x+=1<<i;
    }
    cout<<x;
    return 0;
}
