#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
const int inf=0x3ffffff;
long long r[500005];
long long ans[500005];
long long res[300005];
int le;
vector<int>t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        if(t[i].size()==1){
            r[t[i][0]]=inf;
        }
        int maxn=-1;
        for(int j=0;j<t[i].size();j++){
            if(j!=t[i].size()-1)r[t[i][j]]=t[i][j+1];
            maxn=max(maxn,t[i][j]);
        }
        r[maxn]=inf;
    }
    /*for(int i=1;i<=n;i++){
        cout<<i<<' '<<r[i]<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(r[j]==inf){
                ans[j]++;
                j++;
            }
            else{
                j=r[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        res[a[i]]+=ans[i];
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
