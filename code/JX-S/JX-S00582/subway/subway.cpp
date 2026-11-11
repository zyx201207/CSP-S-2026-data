#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c11,n,m,d,q,w[N],k[505],a[505][N],t[505][N],c[505],ans[N];
struct sss{
    int a,t;
};
vector<int>f[N];
vector<int>f1[N];
void s(int a1){
    queue<int>q;
    q.push(a1);
    while(!q.empty()){
        int s1=q.front();
        q.pop();
        for(int i=0;i<f[s1].size();i++){
            for(int j=1;j<=k[f[s1][i]]+1;j++){
                int ss=f[s1][i];
                if(a[ss][j]!=s1){
                    if(ans[s1]+t[ss][j]+t[ss][f1[s1][i]]<ans[a[f[s1][ss]][j]]){
                        cout<<a[f[s1][ss]][j]<<' '<<ans[s1]<<' '<<t[ss][j]<<' '<<t[ss][f1[s1][i]]<<' '<<s1<<' '<<j<<' '<<ss<<'\n';
                        ans[a[f[s1][ss]][j]]=min(ans[s1]+t[ss][j]+t[ss][f1[s1][i]],ans[a[f[s1][ss]][j]]);
                        q.push(a[f[s1][i]][j]);
                    }
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int mm=0;
    cin>>c11>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            f[a[i][j]].push_back(i);
            f1[a[i][j]].push_back(j);
            mm=max(mm,a[i][i]);
        }
    }
    for(int i=1;i<=mm;i++){
        ans[i]=1e9;
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        ans[l]=0;
        s(l);
        for(int i=1;i<=mm;i++){
            cout<<ans[i]<<' ';
        }
        cout<<ans[r]+w[l]+w[r]<<'\n';
    }
    return 0;
}
